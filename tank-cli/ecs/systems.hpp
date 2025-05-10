#pragma once

#include <glm/glm.hpp>
#include <tank-cli/camera.hpp>
#include <tank-cli/ecs/component-manager.hpp>
#include <tank-cli/ecs/entity-manager.hpp>
#include <tank-cli/map.hpp>
#include <tank-cli/mesh.hpp>
#include <tank-cli/shader-program.hpp>
#include <tank-cli/window.hpp>

class World;

namespace systems {

namespace util {

glm::vec3 yaw2vec(float yaw);

} // namespace util

class Physics {
  public:
    static void update(Entity_manager &em, Component_manager &cm, float dt,
                       ::Map const &map);
};

class Spawner {
  public:
    static void update(Entity_manager &em, Component_manager &cm, ::Map &map);

  private:
    template <typename Tag>
    static void spawn_tank(Entity_manager &em, Component_manager &cm,
                           ::Map &map, Tag tag);
};

class AI {
  public:
    static void update(Entity_manager &em, Component_manager &cm);
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
    /// @param t Time since game started
    static void render(Component_manager &cm, Camera const &cam, Window &window,
                       Shader_program &player_shader,
                       Shader_program &env_shader, float t);
};

class Input {
  public:
    static void update(Component_manager &cm, Window &window);
};

class Weapon {
  public:
    static void update(World &world, float dt);
};

class Expiration {
  public:
    static void update(World &w, float dt);
};

class Resources {
  public:
    static Window &main_window()
    {
        static Window window;
        return window;
    }

    static Shader_program &env_shader()
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
        static Camera camera(std::numbers::pi / 2,
                             (-std::numbers::pi / 3.5) + 0.01F,
                             glm::vec3(map().fwidth() / 2, 100 - 30,
                                       (map().fheight() / 2) + 60));
        return camera;
    }

    static ::Map &map()
    {
        constexpr int width = 80;
        constexpr int height = 60;
        static ::Map map(width + 1, height + 1);
        return map;
    }

    static Mesh &tank()
    {
        float h = 3.0F;
        std::vector<glm::vec3> tank_vertices = {
            {6, h, 3}, {-6, h, 3}, {6, h, -3}, {-6, h, -3},
            {0, h, 1}, {0, h, -1}, {9, h, 1},  {9, h, -1},
            {6, 0, 3}, {-6, 0, 3}, {6, 0, -3}, {-6, 0, -3},
            {0, 0, 1}, {0, 0, -1}, {9, 0, 1},  {9, 0, -1}};
        std::vector<uint32_t> tank_indices = {
            0,  1,  2,  1,  3,  2,  4,  5, 6,  5,  7, 6, 10, 9,  8, 10, 11, 9,
            14, 13, 12, 14, 15, 13, 8,  9, 0,  0,  9, 1, 9,  11, 1, 1,  11, 3,
            11, 10, 3,  3,  10, 2,  10, 8, 2,  2,  8, 0, 12, 14, 4, 4,  14, 6,
            13, 5,  15, 15, 5,  7,  12, 4, 13, 13, 4, 5, 14, 15, 6, 6,  15, 7,
        };
        static Mesh tank(tank_vertices, tank_indices);
        return tank;
    }

    static Mesh &bullet()
    {
        std::vector<glm::vec3> bullet_vertices = {
            {-0.5f, -0.5f, -0.5f}, {0.5f, -0.5f, -0.5f}, {0.5f, 0.5f, -0.5f},
            {-0.5f, 0.5f, -0.5f},  {-0.5f, -0.5f, 0.5f}, {0.5f, -0.5f, 0.5f},
            {0.5f, 0.5f, 0.5f},    {-0.5f, 0.5f, 0.5f}};

        std::vector<uint32_t> bullet_indices = {
            0, 1, 2, 2, 3, 0, // front face
            4, 5, 6, 6, 7, 4, // back face
            7, 3, 0, 0, 4, 7, // left face
            6, 2, 1, 1, 5, 6, // right face
            0, 1, 5, 5, 4, 0, // bottom face
            3, 2, 6, 6, 7, 3  // top face
        };
        static Mesh bullet(bullet_vertices, bullet_indices);
        return bullet;
    }

    static Mesh &barrier_unit()
    {
        // 顶点定义一个沿 X 方向长度=1，沿 Z 方向厚度=1，高度=1 的盒子
        static std::vector<glm::vec3> verts = {
            {-0.5f, -0.5f, -0.5f}, {+0.5f, -0.5f, -0.5f}, {+0.5f, -0.5f, +0.5f},
            {-0.5f, -0.5f, +0.5f}, {-0.5f, +0.5f, -0.5f}, {+0.5f, +0.5f, -0.5f},
            {+0.5f, +0.5f, +0.5f}, {-0.5f, +0.5f, +0.5f},
        };
        static std::vector<uint32_t> idx = {
            0, 1, 2, 2, 3, 0, // bottom
            4, 5, 6, 6, 7, 4, // top
            0, 1, 5, 5, 4, 0, // front
            2, 3, 7, 7, 6, 2, // back
            1, 2, 6, 6, 5, 1, // right
            3, 0, 4, 4, 7, 3  // left
        };
        static Mesh m(verts, idx);
        return m;
    }
};

} // namespace systems
