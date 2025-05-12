#pragma once

#include <algorithm>
#include <chrono>
#include <glm/glm.hpp>
#include <spdlog/spdlog.h>
#include <tank-cli/motion.hpp>

class Map;

class Player {
    friend class Map;

  public:
    Player(std::string name, glm::vec3 position, float direction, Map *map);

    void render() const {}

    void update(float dt)
    {
        motion_sequence_uniform_.consume(*this, dt);
        motion_sequence_turn_.consume(*this, dt);
        last_fire_elapsed_ += dt;
        if (last_fire_elapsed_ >= 1 && should_fire_) {
            fire();
            last_fire_elapsed_ = 0;
        }

        move(dt);
        turn(dt);
        // move(dt);
        // shot();
    }

    // Positive clockwise, negative anti-clockwise
    void turn(float dt);

    // Returns true if collide with others.
    bool move(float dt);

    // To current direction
    void fire() const;

    void set_velocity(float velocity);
    void set_rotation_speed(float rotation_speed);
    void set_should_fire(bool value);

    [[deprecated]] void display_velocity() const
    {
        constexpr int radius = 10;             // 绘制半径
        constexpr int size = (radius * 2) + 1; // 缓冲区大小

        // 创建缓冲区，初始化为空格
        std::vector<std::string> buf(size, std::string(size, ' '));

        // 绘制坐标轴
        for (int i = 0; i < size; ++i) {
            buf[radius][i] = '-'; // x轴
            buf[i][radius] = '|'; // y轴
        }
        buf[radius][radius] = '+'; // 原点

        glm::vec2 velocity_vec = velocity_ * direction_vec();

        // 计算速度方向的终点坐标
        if (glm::length(velocity_vec) > 0.1F) { // 忽略过小的速度
            // 标准化速度向量并缩放到半径长度
            glm::vec2 dir =
                glm::normalize(velocity_vec) * static_cast<float>(radius);

            // 转换到缓冲区坐标 (原点在中心)
            int x1 = radius;
            int y1 = radius;
            int x2 = static_cast<int>(std::round(dir.x)) + radius;
            int y2 = static_cast<int>(std::round(dir.y)) + radius;

            // 确保坐标在缓冲区内
            x2 = std::clamp(x2, 0, size - 1);
            y2 = std::clamp(y2, 0, size - 1);

            // 使用Bresenham算法绘制线段
            int dx = abs(x2 - x1);
            int dy = abs(y2 - y1);
            int sx = x1 < x2 ? 1 : -1;
            int sy = y1 < y2 ? 1 : -1;
            int err = dx - dy;

            while (true) {
                if (x1 >= 0 && x1 < size && y1 >= 0 && y1 < size) {
                    buf[y1][x1] = '*'; // 绘制线段点
                }

                if (x1 == x2 && y1 == y2)
                    break;

                int e2 = 2 * err;
                if (e2 > -dy) {
                    err -= dy;
                    x1 += sx;
                }
                if (e2 < dx) {
                    err += dx;
                    y1 += sy;
                }
            }
        }

        // 打印缓冲区
        for (auto const &line : buf) {
            spdlog::debug("{}", line);
        }
    }

    [[nodiscard]] glm::ivec2 iposition2() const
    {
        return {static_cast<int>(position_.x), static_cast<int>(position_.z)};
    }

    [[nodiscard]] glm::vec2 position2() const
    {
        return {position_.x, position_.z};
    }

    [[deprecated]] void report_state() const
    {
        spdlog::debug("player {} is at {} {}, velocity: {}, direction_: {}",
                      name_, position_.x, position_.z, velocity_, direction_);
    }

    auto &motion_sequence_uniform()
    {
        return motion_sequence_uniform_;
    }

    auto &motion_sequence_turn()
    {
        return motion_sequence_turn_;
    }

    [[nodiscard]] glm::vec3 position() const
    {
        return position_;
    }

    [[nodiscard]] glm::vec3 direction() const
    {
        return {glm::cos(direction_), 0, -glm::sin(direction_)};
    }

    [[nodiscard]] float fdirection() const
    {
        return direction_;
    }

  private:
    std::string name_;
    glm::vec3 position_;
    float direction_{};
    float velocity_{};
    bool should_fire_{};
    float last_fire_elapsed_{};
    float rotation_speed_{}; // in radians
    Map *map_;
    Motion_sequence<motions::Uniform> motion_sequence_uniform_;
    Motion_sequence<motions::Turn> motion_sequence_turn_;

    void set_map(Map *map)
    {
        map_ = map;
    }

    [[nodiscard]] glm::vec2 direction_vec() const
    {
        return {glm::sin(direction_), glm::cos(direction_)};
    }
};
