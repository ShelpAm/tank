#pragma once

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
        auto spawn_barrier = [&](glm::vec2 s, glm::vec2 e) {
            auto id = em_.make();
            cm_.add(id, Barrier{.start = s, .end = e});
            cm_.add(id, Transform{.position = {s.x, 0.F, s.y}, .yaw = 0.F});
            cm_.add(id,
                    Renderable{.mesh = &systems::Resources::barrier_unit()});
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
