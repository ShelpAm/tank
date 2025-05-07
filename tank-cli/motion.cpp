#include <tank-cli/motion.hpp>
#include <tank-cli/player.hpp>

void motions::Uniform::apply(Player &p, float dt)
{
    spdlog::debug("Uniform velocity_: {}", velocity_);
    p.set_velocity(velocity_);
    p.move(dt);
}

void motions::Turn::apply(Player &p, float dt)
{
    spdlog::debug("Turn rotaion_speed_radians_: {}", rotaion_speed_radians_);
    p.turn(dt * rotaion_speed_radians_);
}
