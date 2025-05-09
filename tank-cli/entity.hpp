#pragma once

#include <cstdint>
#include <glm/glm.hpp>
#include <spdlog/spdlog.h>
#include <stdexcept>
#include <tank-cli/camera.hpp>
#include <tank-cli/map.hpp>
#include <tank-cli/mesh.hpp>
#include <tank-cli/shader-program.hpp>
#include <tank-cli/window.hpp>
#include <unordered_map>
#include <vector>

class ECS;
using Entity = std::uint64_t;

template <typename T> class Component_storage {
  public:
    void add(Entity id, T comp)
    {
        if (data_.contains(id)) {
            throw std::runtime_error("entity already contains that component");
        }
        data_.emplace(id, std::move(comp));
        // data_[id] = std::move(comp);
    }

    [[nodiscard]] bool contains(Entity id) const
    {
        return data_.contains(id);
    }

    T &get(Entity id)
    {
        return data_.at(id);
    }

    std::unordered_map<Entity, T> const &all() const
    {
        return data_;
    }

  private:
    std::unordered_map<Entity, T> data_;
};

// Components
struct Transform {
    glm::vec3 position;
};
struct Movement {
    float direction;
    float velocity;
};
struct Weapon {
    float fire_rate;
    float cooldown;
};
struct Intent_to_fire {
    bool active;
};
struct Enemy_tag {};
struct Renderable {
    Mesh mesh;
};

namespace systems {

namespace util {

glm::vec3 yaw2vec(float yaw);

} // namespace util

class Physics {
  public:
    static void update(ECS &ecs, float dt);
};

class Spawner {
  public:
    static void update(ECS &ecs);

  private:
    static void spawn_enemy(ECS &ecs);
};

class AI {
  public:
    static void update(ECS &ecs);
};

class Map {
  public:
    static Map &instance()
    {
        static Map instance;
        return instance;
    }

  private:
};

class Render {
  public:
    static void render(ECS &ecs, Camera const &cam, Window const &window,
                       Shader_program &shader);
};

class Resources {
  public:
    static Window &main_window()
    {
        static Window window;
        return window;
    }

    static Shader_program &shader()
    {
        static Shader_program shader("shader/main.vert", "shader/main.frag");
        return shader;
    }

    static Shader_program &player_shader()
    {
        static Shader_program player_shader("shader/main.vert",
                                            "shader/player.frag");
        return player_shader;
    }

    static Camera &camera()
    {
        static Camera camera(
            std::numbers::pi / 2, (-std::numbers::pi / 3.5) + 0.01F,
            glm::vec3(map().fwidth() / 2, 100 - 30, map().fheight() / 2 + 60));
        return camera;
    }

    static ::Map &map()
    {
        constexpr int width = 80;
        constexpr int height = 60;
        static ::Map map(width + 1, height + 1);
        return map;
    }
};

} // namespace systems

// Entity Component System
class ECS {
  public:
    Entity make_entity()
    {
        return next_entity++;
    }

    template <typename Component> void add(Entity id, Component comp)
    {
        storage<Component>().add(id, std::move(comp));
    }

    template <typename Component> Component &get(Entity id)
    {
        return storage<Component>().get(id);
    }

    template <typename First, typename... Rest> std::vector<Entity> view()
    {
        std::vector<Entity> result;
        auto const &base = storage<First>().all();
        for (auto &&[id, _] : base) {
            if ((storage<Rest>().contains(id) && ...)) {
                result.push_back(id);
            }
        }
        return result;
    }

    void update(float dt)
    {
        systems::Spawner::update(*this);
        systems::AI::update(*this);
        systems::Physics::update(*this, dt);
        systems::Render::render(*this, systems::Resources::camera(),
                                systems::Resources::main_window(),
                                systems::Resources::player_shader());

        GLenum err;
        while ((err = glGetError()) != GL_NO_ERROR) {
            throw std::runtime_error(std::format("OpenGL error: {}", err));
        }
    }

  private:
    Entity next_entity{0};

    template <typename Component> Component_storage<Component> &storage()
    {
        static Component_storage<Component> storage;
        return storage;
    }
};
