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

    void use_window();

    std::vector<Event> take_events()
    {
        poll_events();
        return std::exchange(events_, {});
    }

    void render()
    {
        pre_render();
        on_render();
        post_render();
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

    void set_render_fn(std::function<Render_fn> render_fn)
    {
        render_fn_ = std::move(render_fn);
    }

  private:
    GLFWwindow *window_;
    int width_;
    int height_;
    std::vector<Event> events_;
    std::function<Render_fn> render_fn_;

    static void error_callback(int error, char const *description);
    static void key_callback(GLFWwindow *window, int key, int scancode,
                             int action, int mods);

    void poll_events();

    void pre_render()
    {
        use_window();
        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    void on_render()
    {
        if (render_fn_) {
            render_fn_();
        }
    }
    void post_render()
    {
        glfwSwapBuffers(window_);
    }
};
