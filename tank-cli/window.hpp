#pragma once

#include <functional>
#include <glad/gl.h>
#include <spdlog/spdlog.h>
#include <tank-cli/glfw.hpp>
#include <variant>
#include <vector>

struct Key_event {
    int key;
    int action;
};
struct Mouse_event {}; // TODO(shelpam): imlement this

class Window {
    using Render_fn = void();

  public:
    using Event = std::variant<Key_event>;

    static void initialize();
    static void deinitialize();

    Window();
    Window(Window const &) = delete;
    Window(Window &&) = delete;
    auto operator=(Window const &) -> Window & = delete;
    auto operator=(Window &&) -> Window & = delete;
    virtual ~Window();

    void key_callback(int key, int /*scancode*/, int action, int /*mods*/);

    [[nodiscard]] bool should_close() const;
    void set_should_close(bool value);

    /// @brief GLFWwindow contains GL context, so before any invocation to
    /// OpenGL function, call this.
    void use_window();

    std::vector<Event> take_events()
    {
        return std::exchange(events_, {});
    }

    [[nodiscard]] int width() const
    {
        return width_;
    }

    [[nodiscard]] int height() const
    {
        return width_;
    }

    [[nodiscard]] GLFWwindow *glfw_window()
    {
        return window_;
    }

    void poll_events();

    void swap_buffers();

    // After calling this function, key_pressed_[key] will be cleared (to be 0).
    [[nodiscard]] bool key_pressed(int key)
    {
        auto ret = key_pressed_[key] != 0U;
        key_pressed_[key] = 0;
        return ret;
    }

    [[nodiscard]] bool key_down(int key)
    {
        return key_down_[key] != 0U;
    }

  private:
    GLFWwindow *window_;
    int width_;
    int height_;
    std::vector<Event> events_;
    std::function<Render_fn> render_fn_;
    std::vector<std::uint8_t> key_pressed_; // Once pressed?
    std::vector<std::uint8_t> key_down_;

    static void error_callback(int error, char const *description);
    static void key_callback(GLFWwindow *window, int key, int scancode,
                             int action, int mods);
};
