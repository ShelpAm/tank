#include <print>
#include <random>
#include <ranges>
#include <tank-cli/map.hpp>
#include <tank-cli/motion.hpp>
#include <tank-cli/player.hpp>
#include <tank-cli/shader-program.hpp>
#include <tank-cli/time.hpp>

Map::Map(int width, int height)
    : width_(width), height_(height),
      terrain_(width, std::vector<Terrain>(height, Terrain::movable)),
      is_x_axis_(width, std::vector<bool>(height, false)), tank_radius_(1),
      bullet_radius_(0)
{
}

void Map::add_player(Player &&player)
{
    players_.push_back(std::move(player));
}

//    --------------
//  -/              \-
// |   x==========x   |
//  -\              /-
//    --------------
void Map::add_barrier(Barrier barrier)
{
    auto dir = barrier.end - barrier.start;
    auto const len = std::abs(dir.x) + std::abs(dir.y);
    dir /= len;

    auto ortho = dir;
    std::swap(ortho.x, ortho.y);

    // Circle in endpoints
    //    -            -
    //  -/|            |\-
    // |--|            |--|
    //  -\|            |/-
    //    -            -
    std::vector endpoints{barrier.start, barrier.end};
    for (auto endpoint : endpoints) {
        for (int i{-tank_radius_}; i != tank_radius_ + 1; ++i) {
            for (int j{-tank_radius_}; j != tank_radius_ + 1; ++j) {
                if (i * i + j * j >= tank_radius_ * tank_radius_) {
                    continue;
                }
                glm::ivec3 p(endpoint.x + i, 0, endpoint.y + j);
                if (is_valid(p) && terrain_[p.x][p.z] != Terrain::wall) {
                    terrain_[p.x][p.z] = Terrain::immovable;
                }
            }
        }
    }

    // Rectangle around
    //     ------------
    //     ------------
    //
    //     ------------
    //     ------------
    for (int i{}; i != len + 1; ++i) {
        auto point = barrier.start + dir * i;
        for (int j{-tank_radius_}; j != tank_radius_ + 1; ++j) {
            auto p_ = point + j * ortho;
            glm::ivec3 p(p_.x, 0, p_.y);
            if (is_valid(p) && terrain_[p.x][p.z] != Terrain::wall) {
                terrain_[p.x][p.z] = Terrain::immovable;
            }
        }
    }

    // Finally, the wall itself
    //
    //
    //     x==========x
    //
    //
    for (int i{}; i != len + 1; ++i) {
        auto p_ = barrier.start + dir * i;
        glm::ivec3 p(p_.x, 0, p_.y);
        terrain_[p.x][p.z] = Terrain::wall;
        is_x_axis_[p.x][p.z] = dir.x != 0;
    }

    barriers_.push_back(barrier);
}

namespace {
char terrain2display(Terrain t)
{
    switch (t) {
    case Terrain::wall:
        return '#';
    case Terrain::immovable:
    case Terrain::movable:
        return '.';
    }
    std::unreachable();
}
} // namespace

// void Map::display_terrain() const
// {
//     std::vector map(height_, std::vector<char>(width_));
//
//     for (int i{}; i != height_; ++i) {
//         for (int j{}; j != width_; ++j) {
//             map[i][j] = terrain2display(terrain_[i][j]);
//         }
//     }
//
//     // Render bullets
//     for (auto const &bullet : bullets_) {
//         render_circle(map, bullet.iposition2(), bullet_radius_, '*');
//     }
//
//     // Render players
//     for (auto const &player : players_) {
//         render_circle(map, player.iposition2(), tank_radius_, 'P');
//         // render_line(map, player.position_,
//         //             player.position_ + player.direction_vec() *
//         // static_cast<float>(tank_radius_),
//         //             '@');
//         for (int i{}; i != tank_radius_ + 1; ++i) {
//             auto p = player.position2() +
//                      player.direction_vec() * static_cast<float>(i);
//             map[p.x][p.y] = '@'; // Weapon
//         }
//     }
//
//     // 打印地图
//     for (auto const &row : map) {
//         std::string_view sv(row.begin(), row.end());
//         std::println("{}", sv);
//         // spdlog::debug("{}", buf);
//     }
// }

bool Map::is_visitable(glm::vec3 pos, bool is_bullet, bool *is_x_axis) const
{
    if (!is_valid(pos)) {
        return false;
    }

    if (is_bullet) {
        if (is_x_axis != nullptr) {
            *is_x_axis = is_x_axis_[pos.x][pos.z];
        }
        return terrain_[pos.x][pos.z] != Terrain::wall;
    }

    // For tank
    return terrain_[pos.x][pos.z] == Terrain::movable;
}
void Map::add_bullet(Bullet bullet)
{
    bullets_.push_back(std::move(bullet));
}
void Map::update(float dt)
{
    std::random_device dev;
    std::mt19937 rng(dev());

    // Add sufficient players to the map, as a demo should do.
    static int id{};
    static bool first = true;
    if (first) {
        // Random
        while (players_.size() < 5) {
            spdlog::trace("adding players, current number of players: {}",
                          players_.size());
            glm::vec3 pos{rng() % height_, 0, rng() % width_};
            if (is_visitable(pos)) {
                Player q("Player" + std::to_string(id++), pos, rng() % 100,
                         this);
                add_player(std::move(q));
            }
        }
        // first = false;
    }
    else { // Locked
        // while (players_.size() < 5) {
        //     spdlog::trace("adding players, current number of players: {}",
        //                   players_.size());
        //     glm::vec3 pos{-2, 0, 0};
        //     if (is_visitable(pos)) {
        //         Player q("Player" + std::to_string(id++), pos, rng() % 100,
        //                  this);
        //         add_player(std::move(q));
        //     }
        // }
    }

    for (Player &p : players_ | std::views::drop(1)) {
        spdlog::trace("adding motions");
        if (p.motion_sequence_uniform().empty()) {
            p.motion_sequence_uniform().add_motion(
                motions::Uniform(Durationf(2), rng() % 5 * 2));
        }

        if (p.motion_sequence_turn().empty()) {
            auto tmp = (static_cast<int>(rng() % 9) - 4);
            p.motion_sequence_turn().add_motion(
                motions::Turn(Durationf(2), std::numbers::pi / 16 * tmp * 2));
        }

        p.set_should_fire(true);
    }

    for (auto &player : players_) {
        spdlog::trace("updating player {}", player.name_);
        // player.report_state();
        player.update(dt);
    }

    // Collision detection
    for (auto it = bullets_.begin(); it != bullets_.end();) {
        // Collide with wall
        bool is_x_axis;
        if (!is_visitable(it->position + it->direction * it->velocity * dt,
                          true, &is_x_axis)) {
            if (is_x_axis) {
                it->direction.z *= -1;
            }
            else {
                it->direction.x *= -1;
            }
            ++it;
            // it = bullets_.erase(it);
            continue;
        }
        it->position += it->direction * it->velocity * dt;

        it->remaining -= dt * it->velocity;
        if (it->remaining <= 0) {
            it = bullets_.erase(it);
            continue;
        }

        if (auto jt = std::ranges::find_if( // Collide with tank
                players_,
                [it, this](auto const &player) {
                    return glm::length(player.position_ - it->position) <=
                           tank_radius_;
                });
            jt != players_.end()) {
            players_.erase(jt);
            it = bullets_.erase(it);
            continue;
        }
        // Didn't collide
        ++it;
    }
}

bool Map::is_valid(glm::vec3 pos) const
{
    return 0 <= pos.x && pos.x < width_ && 0 <= pos.z && pos.z < height_;
}
// void Map::render_circle(std::vector<std::vector<char>> &map, glm::vec2 pos,
//                         int radius, char ch) const
// {
//     if (is_valid(pos)) {
//         // 使用'*'表示子弹
//         for (int i{-radius}; i != radius + 1; ++i) {
//             for (int j{-radius}; j != radius + 1; ++j) {
//                 glm::ivec2 dest = pos + glm::vec2(i, j);
//                 if (is_valid(dest) && i * i + j * j <= radius * radius) {
//                     map[dest.x][dest.y] = ch;
//                 }
//             }
//         }
//     }
// }
// void Map::render_line(std::vector<std::vector<char>> &map, glm::vec2 u,
//                       glm::vec2 v, char ch) const
// {
//     auto dir = glm::normalize(v - u);
//     auto len = glm::length(v - u);
//     spdlog::debug("len: {}, dir: ({}, {})", len, dir.x, dir.y);
//     for (int i{}; i != len + 1; ++i) {
//         auto p = u + dir * static_cast<float>(i);
//         if (is_valid(p)) {
//             map[p.x][p.y] = ch;
//         }
//     }
// }
void Map::render(Shader_program &shader, Shader_program &player_shader,
                 std::function<void(Barrier const &)> const &render_barrier)
{
    for (auto const &b : barriers_) {
        render_barrier(b);
    }
}
