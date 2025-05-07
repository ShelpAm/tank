#include <print>
#include <random>
#include <tank-cli/map.hpp>
#include <tank-cli/motion.hpp>
#include <tank-cli/player.hpp>
#include <tank-cli/time.hpp>

Map::Map(int height, int width)
    : height_(height), width_(width),
      terrain_(height, std::vector<Terrain>(width, Terrain::movable)),
      tank_radius_(std::max(width, height) / 30), bullet_radius_(0)
{
}

void Map::add_player(Player &&player)
{
    players_.push_back(std::move(player));
}

void Map::add_barrier(Barrier barrier)
{
    auto dir = barrier.end - barrier.start;
    auto const len = std::abs(dir.x) + std::abs(dir.y);
    dir /= len;

    auto ortho = dir;
    std::swap(ortho.x, ortho.y);

    std::vector endpoints{barrier.start, barrier.end};
    for (auto endpoint : endpoints) {
        for (int i{-tank_radius_}; i != tank_radius_ + 1; ++i) {
            for (int j{-tank_radius_}; j != tank_radius_ + 1; ++j) {
                if (i * i + j * j >= tank_radius_ * tank_radius_) {
                    continue;
                }
                auto p = endpoint + glm::ivec2{i, j};
                if (is_valid(p) && terrain_[p.x][p.y] != Terrain::wall) {
                    terrain_[p.x][p.y] = Terrain::immovable;
                }
            }
        }
    }

    for (int i{}; i != len + 1; ++i) {
        auto point = barrier.start + dir * i;
        for (int j{-tank_radius_}; j != tank_radius_ + 1; ++j) {
            auto p = point + j * ortho;
            if (is_valid(p) && terrain_[p.x][p.y] != Terrain::wall) {
                terrain_[p.x][p.y] = Terrain::immovable;
            }
        }
    }

    for (int i{}; i != len + 1; ++i) {
        auto point = barrier.start + dir * i;
        terrain_[point.x][point.y] = Terrain::wall;
    }
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

void Map::display_terrain() const
{
    std::vector map(height_, std::vector<char>(width_));

    for (int i{}; i != height_; ++i) {
        for (int j{}; j != width_; ++j) {
            map[i][j] = terrain2display(terrain_[i][j]);
        }
    }

    // Render bullets
    for (auto const &bullet : bullets_) {
        render_circle(map, bullet.position(), bullet_radius_, '*');
    }

    // Render players
    for (auto const &player : players_) {
        render_circle(map, player.position(), tank_radius_, 'P');
        // render_line(map, player.position_,
        //             player.position_ + player.direction_vec() *
        //                                    static_cast<float>(tank_radius_),
        //             '@');
        for (int i{}; i != tank_radius_ + 1; ++i) {
            auto p = player.position_ +
                     player.direction_vec() * static_cast<float>(i);
            map[p.x][p.y] = '@'; // Weapon
        }
    }

    // 打印地图
    for (auto const &row : map) {
        std::string_view sv(row.begin(), row.end());
        std::println("{}", sv);
        // spdlog::debug("{}", buf);
    }
}

bool Map::is_visitable(glm::ivec2 pos, bool is_bullet) const
{
    if (!is_valid(pos)) {
        return false;
    }

    if (is_bullet) {
        return terrain_[pos.x][pos.y] != Terrain::wall;
    }

    // For tank
    return terrain_[pos.x][pos.y] == Terrain::movable;
}
void Map::add_bullet(Player &&bullet)
{
    bullets_.push_back(std::move(bullet));
}
void Map::update(float dt)
{
    std::random_device dev;
    std::mt19937 rng(dev());

    // Add sufficient players to the map, as a demo should do.
    static int id{};
    while (players_.size() < 5) {
        glm::vec2 pos{rng() % height_, rng() % width_};
        if (is_visitable(pos)) {
            Player q("Player" + std::to_string(id++), pos, rng() % 1000, this);
            add_player(std::move(q));
        }
    }

    for (Player &p : players_) {
        if (p.motion_sequence_uniform().empty()) {
            p.motion_sequence_uniform().add_motion(
                motions::Uniform(Durationf(2), rng() % 5));
        }

        if (p.motion_sequence_turn().empty()) {
            auto tmp = (static_cast<int>(rng() % 33) - 16);
            p.motion_sequence_turn().add_motion(
                motions::Turn(Durationf(2), std::numbers::pi / 16 * tmp));
        }
    }

    for (auto &player : players_) {
        player.report_state();
        player.update(dt);
    }
    for (auto it = bullets_.begin(); it != bullets_.end();) {
        if (it->move(dt)) { // Collide with wall
            it = bullets_.erase(it);
            continue;
        }
        if (auto jt = std::ranges::find_if( // Collide with tank
                players_,
                [it, this](auto const &player) {
                    return glm::length(player.position_ - it->position_) <=
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

bool Map::is_valid(glm::ivec2 pos) const
{
    return 0 <= pos.x && pos.x < height_ && 0 <= pos.y && pos.y < width_;
}
void Map::render_circle(std::vector<std::vector<char>> &map, glm::vec2 pos,
                        int radius, char ch) const
{
    if (is_valid(pos)) {
        // 使用'*'表示子弹
        for (int i{-radius}; i != radius + 1; ++i) {
            for (int j{-radius}; j != radius + 1; ++j) {
                glm::ivec2 dest = pos + glm::vec2(i, j);
                if (is_valid(dest) && i * i + j * j <= radius * radius) {
                    map[dest.x][dest.y] = ch;
                }
            }
        }
    }
}
void Map::render_line(std::vector<std::vector<char>> &map, glm::vec2 u,
                      glm::vec2 v, char ch) const
{
    auto dir = glm::normalize(v - u);
    auto len = glm::length(v - u);
    spdlog::debug("len: {}, dir: ({}, {})", len, dir.x, dir.y);
    for (int i{}; i != len + 1; ++i) {
        auto p = u + dir * static_cast<float>(i);
        if (is_valid(p)) {
            map[p.x][p.y] = ch;
        }
    }
}
