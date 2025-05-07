#pragma once

#include <glad/gl.h>
#include <spdlog/spdlog.h>
#include <tank-cli/glfw.hpp>

void error_callback(int error, char const *description);

void key_callback(GLFWwindow *window, int key, int scancode, int action,
                  int mods);

class Window {
    friend void key_callback(GLFWwindow *window, int key, int scancode,
                             int action, int mods);

  public:
    static void initialize();
    static void deinitialize();

    Window();
    Window(Window const &) = delete;
    Window(Window &&) = delete;
    auto operator=(Window const &) -> Window & = delete;
    auto operator=(Window &&) -> Window & = delete;
    virtual ~Window();

    virtual void key_callback(int key, int /*scancode*/, int action,
                              int /*mods*/);

    [[nodiscard]] bool should_close() const;
    void set_should_close(bool value);

    void use() const;
    void poll_events() const;
    void render() const;

    [[nodiscard]] GLFWwindow *glfw_window()
    {
        return window_;
    }

  private:
    static std::unordered_map<GLFWwindow *, Window *> forward_table;

    GLFWwindow *window_;
};
