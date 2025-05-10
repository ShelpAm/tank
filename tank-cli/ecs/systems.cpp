#include <random>
#include <spdlog/spdlog.h>
#include <tank-cli/ecs/bundles.hpp>
#include <tank-cli/ecs/components.hpp>
#include <tank-cli/ecs/entity-manager.hpp>
#include <tank-cli/ecs/systems.hpp>
#include <tank-cli/ecs/world.hpp>

glm::vec3 systems::util::yaw2vec(float yaw)
{
    return glm::vec3{std::cos(yaw), 0, -std::sin(yaw)};
}

void systems::Physics::update(Entity_manager &em, Component_manager &cm,
                              float dt, ::Map const &map)
{
    for (Entity id : cm.view<Transform, Velocity>()) {
        auto &t = cm.get<Transform>(id);
        auto &v = cm.get<Velocity>(id);
        if (cm.contains<Player_tag>(id)) {
            auto dest = t.position + util::yaw2vec(t.yaw) * v.linear * dt;
            if (map.is_visitable(dest, false)) {
                t.position = dest;
            }
        }
        else {
            t.position += util::yaw2vec(t.yaw) * v.linear * dt;
        }
        t.yaw += v.angular * dt;
    }

    // Restrict position in map
    for (auto id : cm.view<Tank_tag>()) {
        auto &t = cm.get<Transform>(id);
        t.position.x = std::clamp(t.position.x, 0.F + 3, map.fwidth() - 3);
        t.position.z = std::clamp(t.position.z, 0.F + 3, map.fheight() - 3);
    }

    // Collision detection
    // for (auto it = bullets_.begin(); it != bullets_.end();) {
    //     // Collide with wall
    //     bool is_x_axis;
    //     if (!is_visitable(it->position + it->direction * it->velocity * dt,
    //                       true, &is_x_axis)) {
    //         if (is_x_axis) {
    //             it->direction.z *= -1;
    //         }
    //         else {
    //             it->direction.x *= -1;
    //         }
    //         ++it;
    //         // it = bullets_.erase(it);
    //         continue;
    //     }
    //     it->position += it->direction * it->velocity * dt;
    //
    //     it->remaining -= dt * it->velocity;
    //     if (it->remaining <= 0) {
    //         it = bullets_.erase(it);
    //         continue;
    //     }
    //
    //     if (auto jt = std::ranges::find_if( // Collide with tank
    //             players_,
    //             [it, this](auto const &player) {
    //                 return glm::length(player.position_ - it->position) <=
    //                        tank_radius_;
    //             });
    //         jt != players_.end()) {
    //         players_.erase(jt);
    //         it = bullets_.erase(it);
    //         continue;
    //     }
    //     // Didn't collide
    //     ++it;
    // }
    // Bullet collide with wall
    for (auto id : cm.view<Bullet_tag>()) {
        auto &t = cm.get<Transform>(id);
        auto &v = cm.get<Velocity>(id);
        bool is_x_axis;
        if (!map.is_visitable(t.position, true, &is_x_axis)) {
            if (is_x_axis) {
                t.yaw = 2 * std::numbers::pi - t.yaw;
            }
            else {
                t.yaw = 3 * std::numbers::pi - t.yaw;
            }
        }
    }

    // Collide with tank
    std::vector<Entity> to_remove;
    for (auto id : cm.view<Bullet_tag>()) {
        auto &t = cm.get<Transform>(id);

        auto tanks = cm.view<Tank_tag>();
        auto it = std::ranges::find_if(tanks, [&cm, t](auto tank) {
            return glm::length(cm.get<Transform>(tank).position - t.position) <=
                   1.5F; // Tank radius
        });
        if (it != tanks.end()) {
            to_remove.push_back(*it);
            to_remove.push_back(id);
        }
    }
    for (auto id : to_remove) {
        cm.remove(id);
    }
}

void systems::Spawner::update(Entity_manager &em, Component_manager &cm,
                              ::Map &map)
{
    int const desired_bot_count = 5;
    int current_bot_count =
        static_cast<int>(std::ranges::distance(cm.view<Bot_tag>()));
    spdlog::trace(
        "systems::Spawner desired_bot_count: {}, current_bot_count: {}",
        desired_bot_count, current_bot_count);

    for (int i = 0; i < desired_bot_count - current_bot_count; ++i) {
        spawn_tank(em, cm, map, Bot_tag{});
    }

    if (cm.view<Player_tag>().empty()) {
        spawn_tank(em, cm, map, Player_tag{});
    }
}

template <typename Tag>
void systems::Spawner::spawn_tank(Entity_manager &em, Component_manager &cm,
                                  ::Map &map, Tag tag)
{
    Entity id = em.make();

    std::random_device dev;
    std::mt19937 rng(dev());
    cm.add(id, Tank_tag{});
    cm.add(id, tag);
    cm.add(id, Transform{.position = {rng() % map.width(), 0.0f,
                                      rng() % map.height()},
                         .yaw = 0,
                         .scale = glm::vec3{0.15F}});
    cm.add(id, Velocity{.linear = 0, .angular = 0});
    cm.add(id, Intent_to_fire{.active = false});
    cm.add(id, components::Weapon{
                   .fire_rate = 0.5F, .bullet_speed = 16, .cooldown = 0});
    cm.add(id, Renderable{.mesh = &systems::Resources::tank()});
}

void systems::AI::update(Entity_manager &em, Component_manager &cm)
{
    std::random_device dev;
    std::mt19937 rng(dev());

    for (auto id : cm.view<Bot_tag>()) {
        spdlog::trace("systems::AI entity {} enemy_tag: true", id);
        auto &v = cm.get<Velocity>(id);
        v.linear = rng() % 10;
        v.angular = rng() % 10;
    }

    for (auto id : cm.view<Bot_tag, Intent_to_fire>()) {
        auto &fire = cm.get<Intent_to_fire>(id);
        fire.active = true;
    }
}

void systems::Render::render(Component_manager &cm, Camera const &cam,
                             Window &window, Shader_program &player_shader,
                             Shader_program &env_shader, float t)
{
    window.use_window();
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    player_shader.uniform_1f("time", t);
    env_shader.uniform_1f("time", t);

    auto view = cam.calc_view_matrix();
    auto proj = glm::perspective(std::numbers::pi_v<float> / 4,
                                 static_cast<float>(window.width()) /
                                     static_cast<float>(window.height()),
                                 0.1F, 200.0F);

    for (auto id : cm.view<Transform, Renderable>()) {
        spdlog::trace("systems::Render entity renderable: {}", id);
        auto &t = cm.get<Transform>(id);
        auto &r = cm.get<Renderable>(id);
        glm::mat4 model(1);
        model = glm::translate(model, t.position);
        model = glm::rotate(model, t.yaw, {0, 1, 0});
        model = glm::scale(model, t.scale);
        if (cm.contains<Bot_tag>(id) || cm.contains<Player_tag>(id)) {
            player_shader.uniform_mat4("uMVP", proj * view * model);
            r.mesh->render(player_shader);
        }
        else if (cm.contains<Barrier_tag>(id)) {
            env_shader.uniform_mat4("uMVP", proj * view * model);
            r.mesh->render(env_shader);
        }
        else {
            env_shader.uniform_mat4("uMVP", proj * view * model);
            r.mesh->render(env_shader);
        }
    }

    window.swap_buffers();
    window.poll_events();
}

void systems::Input::update(Component_manager &cm, Window &window)
{
    auto w = window.key_down(GLFW_KEY_W);
    auto a = window.key_down(GLFW_KEY_A);
    auto s = window.key_down(GLFW_KEY_S);
    auto d = window.key_down(GLFW_KEY_D);
    auto j = window.key_pressed(GLFW_KEY_J);

    auto players = cm.view<Player_tag>();
    if (!players.empty()) {
        auto id = players.front();
        cm.get<Velocity>(id).angular = std::numbers::pi / 4 * 8 * (a - d);
        cm.get<Velocity>(id).linear = (w == s ? 0 : w ? 15 : -10);
        cm.get<Intent_to_fire>(id).active ^= j;
    }
}

void systems::Weapon::update(World &world, float dt)
{
    for (auto id :
         world.cm().view<Transform, components::Weapon, Intent_to_fire>()) {
        auto &t = world.cm().get<Transform>(id);
        auto &w = world.cm().get<components::Weapon>(id);
        auto &i = world.cm().get<Intent_to_fire>(id);

        w.cooldown -= dt;
        if (w.cooldown <= 0.F && i.active) {
            w.cooldown = 1.F / w.fire_rate;
            make_bullet(
                world,
                Transform{.position = t.position + util::yaw2vec(t.yaw) * 2.F,
                          .yaw = t.yaw,
                          .scale = glm::vec3{0.2}},
                Velocity{.linear = w.bullet_speed, .angular = 0},
                Renderable{.mesh = &systems::Resources::bullet()},
                components::Expirable{.remaining_time = 8});
        }
    }
}

void systems::Expiration::update(World &w, float dt)
{
    std::vector<Entity> expired;
    for (auto id : w.cm().view<components::Expirable>()) {
        w.cm().get<components::Expirable>(id).remaining_time -= dt;
        if (w.cm().get<components::Expirable>(id).remaining_time <= 0) {
            expired.push_back(id);
        }
    }
    for (auto id : expired) {
        w.cm().remove(id);
    }
}
