#pragma once

#include <glm/glm.hpp>

class Mesh;

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
struct Weapon {
    float fire_rate;
    float cooldown;
};
struct Intent_to_fire {
    bool active;
};

struct Player_tag {};
struct Barrier_rag {};

struct Renderable {
    Mesh *mesh;
};
