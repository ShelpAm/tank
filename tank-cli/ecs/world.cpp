#include <tank-cli/ecs/components.hpp>
#include <tank-cli/ecs/world.hpp>

World::World()
{
    init();
}

void World::init()
{
    // Somewhere in World::init() or your InitSystem:
    {
        auto width = systems::Resources::map().fwidth();
        auto height = systems::Resources::map().fheight();

        // helper lambda to spawn one barrier entity
        auto spawn_barrier = [&](glm::vec2 s2, glm::vec2 e2) {
            // 1) Create entity and base components
            auto id = em_.make();
            cm_.add(id, Barrier_rag{});
            cm_.add(id,
                    Transform{.position = {}, .yaw = 0, .scale = glm::vec3{1}});

            // 2) Compute the eight corner verts of the box
            glm::vec3 s{s2.x, 0.F, s2.y};
            glm::vec3 e{e2.x, 0.F, e2.y};

            auto dir = glm::normalize(e - s);
            auto right = glm::normalize(glm::cross(dir, {0, 1, 0}));

            constexpr float half_width = 0.5F;
            constexpr float half_height = 3.2F;

            // bottom face verts (y = -halfHeight)
            std::vector<glm::vec3> verts = {
                s + right * half_width + glm::vec3{0, -half_height, 0},
                s - right * half_width + glm::vec3{0, -half_height, 0},
                e + right * half_width + glm::vec3{0, -half_height, 0},
                e - right * half_width + glm::vec3{0, -half_height, 0},
                // top face verts (y = +halfHeight)
                s + right * half_width + glm::vec3{0, half_height, 0},
                s - right * half_width + glm::vec3{0, half_height, 0},
                e + right * half_width + glm::vec3{0, half_height, 0},
                e - right * half_width + glm::vec3{0, half_height, 0},
            };

            // 3) Define the 12 triangles (36 indices) for the box
            std::vector<uint32_t> idx = {// bottom
                                         0, 1, 2, 2, 1, 3,
                                         // top
                                         4, 6, 5, 6, 7, 5,
                                         // front (s-side)
                                         0, 2, 4, 4, 2, 6,
                                         // back (e-side)
                                         1, 5, 3, 3, 5, 7,
                                         // left
                                         1, 0, 5, 5, 0, 4,
                                         // right
                                         2, 3, 6, 6, 3, 7};

            // 4) Create a new Mesh with these verts+indices
            auto *mesh = new Mesh(verts, idx);

            // 5) Attach it
            cm_.add(id, Renderable{.mesh = mesh});
        };

        // outer rectangle
        spawn_barrier({0, 0}, {width, 0});
        spawn_barrier({width, 0}, {width, height});
        spawn_barrier({width, height}, {0, height});
        spawn_barrier({0, height}, {0, 0});

        // two interior lines
        spawn_barrier({width / 3.f, 0}, {width / 3.f, height / 3.f * 2});
        spawn_barrier({width / 3.f * 2, height / 3.f},
                      {width / 3.f * 2, height});
    }
}

void World::update(float dt, float t)
{
    systems::Input::update(cm_, systems::Resources::main_window());
    systems::Spawner::update(em_, cm_);
    systems::AI::update(em_, cm_);
    systems::Physics::update(em_, cm_, dt);
    systems::Render::render(cm_, systems::Resources::camera(),
                            systems::Resources::main_window(),
                            systems::Resources::player_shader(),
                            systems::Resources::env_shader(), t);

    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR) {
        throw std::runtime_error(std::format("OpenGL error: {}", err));
    }
}
