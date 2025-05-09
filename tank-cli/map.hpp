#pragma once

#include <glm/glm.hpp>
#include <list>
#include <spdlog/spdlog.h>
#include <tank-cli/bullet.hpp>
#include <vector>

class Shader_program;
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
    friend int main(int argc, char **argv);

  public:
    Map(int height, int width);

    void update(float dt);
    void
    render(Shader_program &, Shader_program &,
           std::function<void(Shader_program &, Player const &, bool)> const
               &render_func,
           std::function<void(Shader_program &, Bullet)> const &render_bullet,
           std::function<void(Barrier const &)> const &render_barrier);

    void add_barrier(Barrier barrier);
    void add_bullet(Bullet bullet);
    void add_player(Player &&player);

    void display_terrain() const;

    [[nodiscard]] int height() const
    {
        return height_;
    }

    [[nodiscard]] int width() const
    {
        return width_;
    }

    [[nodiscard]] float fheight() const
    {
        return height_;
    }

    [[nodiscard]] float fwidth() const
    {
        return width_;
    }

  private:
    int width_;
    int height_;
    std::vector<std::vector<Terrain>> terrain_;
    std::vector<std::vector<bool>> is_x_axis_;
    std::vector<Barrier> barriers_;
    int tank_radius_;
    int bullet_radius_;
    std::vector<Player> players_;
    std::list<Bullet> bullets_;

    [[nodiscard]] bool is_valid(glm::vec3 pos) const;
    [[nodiscard]] bool is_visitable(glm::vec3 pos, bool is_bullet = false,
                                    bool *is_x_axis = nullptr) const;
    void render_circle(std::vector<std::vector<char>> &map, glm::vec2 pos,
                       int radius, char ch) const;
    void render_line(std::vector<std::vector<char>> &map, glm::vec2 u,
                     glm::vec2 v, char ch) const;
};
