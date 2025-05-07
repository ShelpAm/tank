#pragma once

#include <glm/glm.hpp>
#include <list>
#include <spdlog/spdlog.h>
#include <vector>

class Player;

struct Line {
    glm::ivec2 start;
    glm::ivec2 end;
};

enum class Direction : std::uint8_t { horizontal, vertical };

using Barrier = Line;

enum class Terrain : std::uint8_t { wall, immovable, movable };

class Map {
    friend class Player;

  public:
    Map(int height, int width);

    void update(float dt);

    void add_barrier(Barrier barrier);
    void add_bullet(Player &&bullet);
    void add_player(Player &&player);

    void display_terrain() const;

  private:
    int height_;
    int width_;
    std::vector<std::vector<Terrain>> terrain_;
    std::vector<Barrier> barriers_;
    int tank_radius_;
    int bullet_radius_;
    std::vector<Player> players_;
    std::list<Player> bullets_;

    [[nodiscard]] bool is_valid(glm::ivec2 pos) const;
    [[nodiscard]] bool is_visitable(glm::ivec2 pos,
                                    bool is_bullet = false) const;
    void render_circle(std::vector<std::vector<char>> &map, glm::vec2 pos,
                       int radius, char ch) const;
    void render_line(std::vector<std::vector<char>> &map, glm::vec2 u,
                     glm::vec2 v, char ch) const;
};
