#include <ranges>
#include <tank-cli/map.hpp>
#include <tank-cli/player.hpp>
#include <utility>

Player::Player(std::string name, glm::vec2 position, float direction, Map *map)
    : name_(std::move(name)), position_(position), direction_(direction),
      map_(map)
{
}
bool Player::move(float dt)
{
    spdlog::trace("player {} movement update {}s", name_, dt);
    glm::vec2 dest = position_ + dt * velocity_ * direction_vec();
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
void Player::shot() const
{
    Player bullet("bullet",
                  position_ +
                      static_cast<float>(map_->tank_radius_) * direction_vec(),
                  direction_, map_);
    bullet.set_velocity(10);
    map_->add_bullet(std::move(bullet));
}
