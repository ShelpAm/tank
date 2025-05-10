#include <tank-cli/ecs/component-manager.hpp>
#include <tank-cli/ecs/components.hpp>

void Component_manager::remove(Entity id)
{
    storage<Bullet_tag>().remove(id);
    storage<Player_tag>().remove(id);
    storage<Bot_tag>().remove(id);
    storage<Barrier_rag>().remove(id);

    storage<Transform>().remove(id);
    storage<Velocity>().remove(id);
    storage<Intent_to_fire>().remove(id);
    storage<Renderable>().remove(id);
    storage<components::Weapon>().remove(id);
}
