#pragma once

#include <queue>
#include <spdlog/spdlog.h>
#include <tank-cli/time.hpp>

class Player;

using Durationf = std::chrono::duration<float>;

class Motion {
  public:
    Motion(Durationf total_time) : total_time_(total_time) {}

    ~Motion() = default;

    void consume(Player &p, float dt)
    {
        auto slice = std::min(Durationf(dt), total_time_ - elapsed_);
        elapsed_ += slice;
        spdlog::debug("motion:: Motion elapsed_: {}, dt: {}", elapsed_.count(),
                      Durationf(dt).count());
        apply(p, dt);
    }

    [[nodiscard]] bool is_ended() const
    {
        spdlog::debug("motions:: Motion is_ended: {}", elapsed_ >= total_time_);
        return elapsed_ >= total_time_;
    }

  private:
    Durationf total_time_; // Total duration of motion
    Durationf elapsed_{};  // Time elapsed

    virtual void apply(Player &p, float dt) = 0;
};

namespace motions {

class Uniform : public Motion {
  public:
    Uniform(Durationf duration, float velocity)
        : Motion(duration), velocity_(velocity)
    {
    }

    virtual ~Uniform() = default;

  private:
    float velocity_;

    void apply(Player &p, float dt) override;
};

class Turn : public Motion {
  public:
    Turn(Durationf duration, float rotaion_speed_radians)
        : Motion(duration), rotaion_speed_radians_(rotaion_speed_radians)
    {
    }

    virtual ~Turn() = default;

  private:
    float rotaion_speed_radians_;

    void apply(Player &p, float dt) override;
};

} // namespace motions

template <typename Motion_type> class Motion_sequence {
  public:
    void add_motion(Motion_type motion)
    {
        motion_queue_.push(motion);
    }

    void consume(Player &p, float dt)
    {
        if (motion_queue_.empty()) {
            return;
        }

        auto &motion = motion_queue_.front();
        motion.consume(p, dt);

        if (motion.is_ended()) {
            motion_queue_.pop();
        }
    }

    [[nodiscard]] bool empty() const
    {
        return motion_queue_.empty();
    }

  private:
    std::queue<Motion_type> motion_queue_;
};
