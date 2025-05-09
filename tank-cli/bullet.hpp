#pragma once

#include <glm/glm.hpp>

struct Bullet {
  public:
    glm::vec3 direction;
    glm::vec3 position;
    float velocity;
};
