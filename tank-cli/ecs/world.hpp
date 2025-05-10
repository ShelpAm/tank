#pragma once

#include <tank-cli/ecs/component-manager.hpp>
#include <tank-cli/ecs/entity-manager.hpp>
#include <tank-cli/ecs/systems.hpp>

// Entity Component System
class World {
  public:
    World();
    void init();
    void update(float dt, float t);

    [[nodiscard]] Entity_manager &em()
    {
        return em_;
    }

    [[nodiscard]] Component_manager &cm()
    {
        return cm_;
    }

  private:
    Entity_manager em_;
    Component_manager cm_;
};
