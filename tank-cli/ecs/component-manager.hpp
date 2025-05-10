#pragma once

#include <ranges>
#include <stdexcept>
#include <tank-cli/ecs/entity.hpp>
#include <unordered_map>
#include <vector>

template <typename T> class Component_storage {
  public:
    void add(Entity id, T comp)
    {
        if (entities_.contains(id)) {
            throw std::runtime_error("entity already contains that component");
        }
        entities_.emplace(id, std::move(comp));
        // data_[id] = std::move(comp);
    }

    [[nodiscard]] bool contains(Entity id) const
    {
        return entities_.contains(id);
    }

    T &get(Entity id)
    {
        return entities_.at(id);
    }

    void remove(Entity id)
    {
        entities_.erase(id);
    }

    std::unordered_map<Entity, T> const &entities() const
    {
        return entities_;
    }

  private:
    std::unordered_map<Entity, T> entities_;
};

class Component_manager {
  public:
    template <typename Component> void add(Entity id, Component comp)
    {
        storage<Component>().add(id, std::move(comp));
    }

    template <typename Component> Component &get(Entity id)
    {
        return storage<Component>().get(id);
    }

    template <typename Component> [[nodiscard]] bool contains(Entity id)
    {
        return storage<Component>().contains(id);
    }

    void remove(Entity id);

    template <typename First, typename... Rest> std::vector<Entity> eager_view()
    {
        std::vector<Entity> result;
        auto const &base = storage<First>().entities();
        for (auto &&[id, _] : base) {
            if ((storage<Rest>().contains(id) && ...)) {
                result.push_back(id);
            }
        }
        return result;
    }

    template <typename First, typename... Rest> auto view()
    {
        auto const &base = storage<First>().entities() | std::views::keys;
        auto filtered = base | std::views::filter([this](auto id) {
                            return (storage<Rest>().contains(id) && ...);
                        });
        return filtered;
    }

  private:
    template <typename Component> Component_storage<Component> &storage()
    {
        static Component_storage<Component> storage;
        return storage;
    }
};
