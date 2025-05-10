#include <random>
#include <spdlog/spdlog.h>
#include <tank-cli/ecs/components.hpp>
#include <tank-cli/ecs/entity-manager.hpp>
#include <tank-cli/ecs/systems.hpp>
#include <tank-cli/ecs/world.hpp>

glm::vec3 systems::util::yaw2vec(float yaw)
{
    return glm::vec3{std::cos(yaw), 0, -std::sin(yaw)};
}

void systems::Physics::update(Entity_manager &em, Component_manager &cm,
                              float dt)
{
    for (Entity id : cm.view<Transform, Velocity>()) {
        auto &t = cm.get<Transform>(id);
        auto &v = cm.get<Velocity>(id);
        t.position += util::yaw2vec(t.yaw) * v.linear * dt;
        t.yaw += v.angular * dt;
    }
}

void systems::Spawner::update(Entity_manager &em, Component_manager &cm)
{
    int const desired_enemy_count = 5;
    int current =
        static_cast<int>(std::ranges::distance(cm.view<Player_tag>()));

    for (int i = 0; i < desired_enemy_count - current; ++i) {
        spawn_enemy(em, cm);
    }
}

void systems::Spawner::spawn_enemy(Entity_manager &em, Component_manager &cm)
{
    Entity id = em.make();

    cm.add(id, Transform{.position = {rand() % 10, 0.0f, rand() % 10}});
    cm.add(id, Velocity{.linear = 0, .angular = 0});
    cm.add(id, Player_tag{});
    cm.add(id, Intent_to_fire{.active = true});
    cm.add(id, Renderable{.mesh = &systems::Resources::tank()});
}

void systems::AI::update(Entity_manager &em, Component_manager &cm)
{
    std::random_device dev;
    std::mt19937 rng(dev());

    for (auto id : cm.view<Player_tag>()) {
        spdlog::trace("systems::AI entity {} enemy_tag: true", id);
        auto &v = cm.get<Velocity>(id);
        v.linear = rng() % 10;
        v.angular = rng() % 10;
    }

    for (auto id : cm.view<Player_tag, Transform, Velocity, Intent_to_fire>()) {
        auto &fire = cm.get<Intent_to_fire>(id);
        auto &trans = cm.get<Transform>(id);
        auto &movement = cm.get<Velocity>(id);

        if (fire.active) {
            auto bullet = em.make();
            cm.add(bullet,
                   Transform{.position = trans.position + // * radius
                                         util::yaw2vec(trans.yaw) * 1.F,
                             .yaw = trans.yaw});
            cm.add(bullet, Velocity{.linear = 30, .angular = 0});
            cm.add(bullet, Renderable{.mesh = &systems::Resources::bullet()});
        }
    }
}

void systems::Render::render(Component_manager &cm, Camera const &cam,
                             Window const &window,
                             Shader_program &player_shader,
                             Shader_program &env_shader, float t)
{
    player_shader.uniform_1f("time", t);
    env_shader.uniform_1f("time", t);

    auto view = cam.calc_view_matrix();
    auto proj = glm::perspective(std::numbers::pi_v<float> / 4,
                                 static_cast<float>(window.width()) /
                                     static_cast<float>(window.height()),
                                 0.1F, 200.0F);
    for (auto id : cm.view<Transform, Renderable>()) {
        // Non-barrier
        if (cm.contains<Barrier>(id)) {
            continue;
        }
        spdlog::trace("systems::Render entity renderable: {}", id);
        auto &t = cm.get<Transform>(id);
        auto &r = cm.get<Renderable>(id);
        glm::mat4 model(1);
        model = glm::translate(model, t.position);
        model = glm::rotate(model, t.yaw, {0, 1, 0});
        model = glm::scale(model, glm::vec3{0.15F});
        player_shader.uniform_mat4("uMVP", proj * view * model);
        r.mesh->render(player_shader);
    }

    for (auto id : cm.view<Barrier, Transform, Renderable>()) {
        spdlog::debug("systems::Render rendering barrier: {}", id);
        auto &b = cm.get<Barrier>(id);
        auto &t = cm.get<Transform>(id);
        auto &r = cm.get<Renderable>(id);

        // 1. 计算中心线的两个端点
        glm::vec3 s(b.start.x, 0, b.start.y);
        glm::vec3 e(b.end.x, 0, b.end.y);

        glm::mat4 model(1);
        model = glm::translate(model, t.position);
        player_shader.uniform_mat4("uMVP", proj * view * model);
        r.mesh->render(env_shader);
    }
}

void systems::Input::update(Component_manager &cm, Window &window)
{
    auto w = window.key_down(GLFW_KEY_W);
    auto a = window.key_down(GLFW_KEY_A);
    auto s = window.key_down(GLFW_KEY_S);
    auto d = window.key_down(GLFW_KEY_D);
    auto j = window.key_pressed(GLFW_KEY_J);

    if (j) {
        auto players = cm.view<Player_tag>();
        for (auto p : players) {
            auto &i = cm.get<Intent_to_fire>(p);
            i.active ^= 1;
        }
    }
}
