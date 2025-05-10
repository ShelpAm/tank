#include <tank-cli/ecs/component-manager.hpp>
#include <tank-cli/ecs/components.hpp>

// Remember to update this list once added some components! (hint use reflection
// to implement this)
void Component_manager::remove(Entity id)
{
    storage<Barrier_tag>().remove(id);
    storage<Bot_tag>().remove(id);
    storage<Bullet_tag>().remove(id);
    storage<Player_tag>().remove(id);
    storage<Tank_tag>().remove(id);

    storage<Transform>().remove(id);
    storage<Velocity>().remove(id);
    storage<Intent_to_fire>().remove(id);
    storage<Renderable>().remove(id);
    storage<components::Weapon>().remove(id);
    storage<components::Expirable>().remove(id);
}
