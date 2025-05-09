#include <ranges>
#include <tank-cli/map.hpp>
#include <tank-cli/player.hpp>
#include <utility>

Player::Player(std::string name, glm::vec3 position, float direction, Map *map)
    : name_(std::move(name)), position_(position), direction_(direction),
      map_(map)
{
}
bool Player::move(float dt)
{
    spdlog::trace("player {} movement update {}s", name_, dt);
    glm::vec3 dest = position_ + dt * velocity_ * direction();
    spdlog::trace("player {} wants to move to ({}, {})", name_, position_.x,
                  position_.y);
    if (!map_->is_visitable(dest, name_ == "bullet")) {
        return true;
    }
    position_ = dest;
    spdlog::trace("player {} moved to ({}, {})", name_, position_.x,
                  position_.y);
    return false;
}
void Player::fire() const
{
    Bullet bullet{.direction = direction(),
                  .position =
                      position_ +
                      static_cast<float>(map_->tank_radius_) * direction(),
                  .velocity = 10};
    map_->add_bullet(bullet);
}
void Player::turn(float dt)
{
    spdlog::trace("player {} turned {}", name_, dt * rotation_speed_);
    direction_ += dt * rotation_speed_;
}

void Player::set_velocity(float velocity)
{
    velocity_ = velocity;
}

void Player::set_rotation_speed(float rotation_speed)
{
    rotation_speed_ = rotation_speed;
}

void Player::set_should_fire(bool value)
{
    should_fire_ = value;
}
