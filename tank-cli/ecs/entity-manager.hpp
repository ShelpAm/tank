#pragma once

#include <cstdint>
#include <tank-cli/ecs/entity.hpp>

using Entity = std::uint64_t;

class Entity_manager {
  public:
    Entity make()
    {
        return next_entity++;
    }

  private:
    Entity next_entity{0};
};
