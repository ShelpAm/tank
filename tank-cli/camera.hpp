#pragma once

#include <glm/ext/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <numbers>

class Camera {
  public:
    Camera(float yaw, float pitch, glm::vec3 pos)
        : yaw_(yaw), pitch_(pitch), position_(pos)
    {
        assert(std::abs(pitch) < std::numbers::pi / 2);
    }

    [[nodiscard]] glm::mat4 calc_view_matrix() const
    {
        glm::vec3 dir{std::cos(pitch_) * std::cos(yaw_), std::sin(pitch_),
                      -std::cos(pitch_) * std::sin(yaw_)};
        auto right = glm::normalize(glm::cross(dir, world_up));
        auto up = glm::normalize(glm::cross(right, dir));
        return glm::lookAt(position_, position_ + dir, up);
    }

  private:
    static constexpr glm::vec3 world_up{0, 1, 0};
    float yaw_;
    float pitch_;
    // float roll_;
    glm::vec3 position_;
};
