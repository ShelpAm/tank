#pragma once

#include <glm/glm.hpp>

class Mesh;

struct Barrier_tag {};
struct Bullet_tag {};
struct Bot_tag {};
struct Player_tag {};
struct Tank_tag {};

// Components
struct Transform {
    glm::vec3 position = glm::vec3{};
    float yaw = 0;
    glm::vec3 scale = glm::vec3{1};
};
struct Velocity {
    float linear;
    float angular;
};

struct Renderable {
    Mesh *mesh;
};

namespace components {

struct Weapon {
    float fire_rate;
    float bullet_speed;
    float cooldown;
    bool active;
};

struct Expirable {
    float remaining_time;
};

} // namespace components
