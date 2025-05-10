#pragma once

#include <tank-cli/ecs/components.hpp>
#include <tank-cli/ecs/world.hpp>

Entity make_bullet(World &w, Transform t, Velocity v, Renderable r)
{
    auto bullet = w.em().make();
    w.cm().add(bullet, Bullet_tag{});
    w.cm().add(bullet, t);
    w.cm().add(bullet, v);
    w.cm().add(bullet, r);
    return bullet;
}
