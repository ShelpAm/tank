#pragma once

#include <glm/glm.hpp>

class Mesh;

// Components
struct Transform {
    glm::vec3 position;
    float yaw;
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
struct Renderable {
    Mesh *mesh;
};
