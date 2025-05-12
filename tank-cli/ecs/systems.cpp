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

auto systems::util::rand()
{
    static std::random_device dev;
    static std::mt19937 rng(dev());
    auto ret = rng();
    spdlog::trace("systems::util::rand returns: {}", ret);
    return ret;
}

void systems::Physics::update(Entity_manager &em, Component_manager &cm,
                              float dt, ::Map const &map)
{
    for (Entity id : cm.view<Transform, Velocity>()) {
        auto &t = cm.get<Transform>(id);
        auto &v = cm.get<Velocity>(id);
        // For tanks
        if (cm.contains<Tank_tag>(id)) {
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

    // Collision detection
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

    // Collision between bullet and tank
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

void systems::Spawner::update(World &w, ::Map &map)
{
    int const desired_bot_count = 5;
    int current_bot_count =
        static_cast<int>(std::ranges::distance(w.cm().view<Bot_tag>()));

    spdlog::trace(
        "systems::Spawner desired_bot_count: {}, current_bot_count: {}",
        desired_bot_count, current_bot_count);

    for (int i = 0; i < desired_bot_count - current_bot_count; ++i) {
        spawn_tank(w, map, Bot_tag{});
    }

    while (w.cm().eager_view<Player_tag>().size() < 2) {
        spawn_tank(w, map, Player_tag{});
        spawn_tank(w, map, Player_tag{});
    }
}

template <typename Tag>
Entity systems::Spawner::spawn_tank(World &w, ::Map &map, Tag player_or_bot_tag,
                                    Transform t, Velocity v,
                                    components::Weapon weapon)
{
    Entity id = w.em().make();
    w.cm().add(id, Tank_tag{});
    w.cm().add(id, player_or_bot_tag);
    w.cm().add(id, t);
    w.cm().add(id, v);
    w.cm().add(id, weapon);
    w.cm().add(id, Renderable{.mesh = &systems::Resources::tank()});
    return id;
}

template <typename Tag>
Entity systems::Spawner::spawn_tank(World &w, ::Map &map, Tag player_or_bot_tag)
{
    // Generate a visitable position to place the tank.
    glm::vec3 position;
    do {
        position = {util::rand() % map.width(), 0.0F,
                    util::rand() % map.height()};
    } while (!map.is_visitable(position));

    return spawn_tank(
        w, map, player_or_bot_tag,
        Transform{.position = position, .yaw = 0, .scale = glm::vec3{0.15F}},
        Velocity{.linear = 0, .angular = 0},
        components::Weapon{.fire_rate = 0.5F,
                           .bullet_speed = 16,
                           .cooldown = 0,
                           .active = false});
}

Entity systems::Spawner::spawn_bullet(World &w, Transform t, Velocity v,
                                      Renderable r, components::Expirable e)
{
    auto bullet = w.em().make();
    w.cm().add(bullet, Bullet_tag{});
    w.cm().add(bullet, t);
    w.cm().add(bullet, v);
    w.cm().add(bullet, r);
    w.cm().add(bullet, e);
    return bullet;
}

void systems::AI::update(Entity_manager &em, Component_manager &cm)
{

    // Randomize bot's velocity and remove their intent to fire
    for (auto id : cm.view<Bot_tag, components::Weapon>()) {
        spdlog::trace("systems::AI entity {} enemy_tag: true", id);
        auto &v = cm.get<Velocity>(id);
        auto &fire = cm.get<components::Weapon>(id);
        v.linear = util::rand() % 15;
        v.angular = util::rand() % 5;
        fire.active = false;
    }
}

void systems::Input::update(Component_manager &cm, Window &window)
{
    auto esc = window.key_pressed(GLFW_KEY_ESCAPE);
    auto w = window.key_down(GLFW_KEY_W);
    auto a = window.key_down(GLFW_KEY_A);
    auto s = window.key_down(GLFW_KEY_S);
    auto d = window.key_down(GLFW_KEY_D);
    auto q = window.key_pressed(GLFW_KEY_Q);
    auto up = window.key_down(GLFW_KEY_UP);
    auto down = window.key_down(GLFW_KEY_DOWN);
    auto left = window.key_down(GLFW_KEY_LEFT);
    auto right = window.key_down(GLFW_KEY_RIGHT);
    auto m = window.key_pressed(GLFW_KEY_M);

    if (esc) {
        std::exit(0);
    }

    auto players = cm.eager_view<Player_tag>();
    if (players.size() >= 1) {
        auto p1 = *std::ranges::next(players.begin(), 0);
        cm.get<Velocity>(p1).angular = std::numbers::pi / 4 * 8 * (a - d);
        cm.get<Velocity>(p1).linear = (w == s ? 0 : w ? 15 : -10);
        cm.get<components::Weapon>(p1).active ^= q;
    }
    if (players.size() >= 2) {
        auto p2 = *std::ranges::next(players.begin(), 1);
        cm.get<Velocity>(p2).angular =
            std::numbers::pi / 4 * 8 * (left - right);
        cm.get<Velocity>(p2).linear = (up == down ? 0 : up ? 15 : -10);
        cm.get<components::Weapon>(p2).active ^= m;
    }
}

void systems::Weapon_system::update(World &world, float dt)
{
    for (auto id : world.cm().view<Tank_tag, Transform, components::Weapon>()) {
        auto &t = world.cm().get<Transform>(id);
        auto &w = world.cm().get<components::Weapon>(id);

        w.cooldown -= dt;
        if (w.cooldown <= 0.F && w.active) {
            w.cooldown = 1.F / w.fire_rate;
            Spawner::spawn_bullet(
                world,
                Transform{.position = t.position + util::yaw2vec(t.yaw) * 2.F,
                          .yaw = t.yaw,
                          .scale = glm::vec3{0.2}},
                Velocity{.linear = w.bullet_speed, .angular = 0},
                Renderable{.mesh = &systems::Resources::bullet()},
                components::Expirable{.remaining_time = 8});

            if (world.cm().contains<Player_tag>(id)) {
                w.active = false;
            }
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
