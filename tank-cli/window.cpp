#include <array>
#include <tank-cli/window.hpp>

void Window::initialize()
{
    glfwSetErrorCallback(Window::error_callback);

    if (glfwInit() == 0) {
        // Initialization failed
        throw std::runtime_error{"Failed to initialize GLFW"};
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Window::deinitialize()
{
    glfwTerminate();
}

Window::Window()
    : window_{glfwCreateWindow(1600, 1200, "tank", nullptr, nullptr)},
      width_(1600), height_(1200), key_pressed_(GLFW_KEY_LAST + 1, 0),
      key_down_(GLFW_KEY_LAST + 1, 0)
{
    if (window_ == nullptr) {
        throw std::runtime_error{"Window or OpenGL context creation failed"};
    }

    glfwSetWindowUserPointer(window_, this);
    glfwSetKeyCallback(window_, Window::key_callback);
    int width;
    int height;
    glfwGetFramebufferSize(window_, &width, &height);

    use_window();
    glfwSwapInterval(1);
    glViewport(0, 0, width, height);
}

Window::~Window()
{
    glfwDestroyWindow(window_);
}

void Window::use_window()
{
    glfwMakeContextCurrent(window_);
}

void Window::poll_events()
{
    use_window();
    glfwPollEvents();
}

bool Window::should_close() const
{
    return glfwWindowShouldClose(window_) != 0;
}
void Window::key_callback(int key, int /*scancode*/, int action, int /*mods*/)
{
    // // Default: Press Esc to close the window.
    // if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    //     glfwSetWindowShouldClose(window_, GLFW_TRUE);
    // }

    events_.emplace_back(Key_event{.key = key, .action = action});
    if (action == GLFW_PRESS) {
        key_pressed_[key] = 1;
        key_down_[key] = 1;
    }
    else if (action == GLFW_RELEASE) {
        key_down_[key] = 0;
    }
}
void Window::set_should_close(bool value)
{
    glfwSetWindowShouldClose(window_, static_cast<int>(value));
}

void Window::error_callback(int error, char const *description)
{
    throw std::runtime_error(std::format("GLFW({}): {}", error, description));
}

void Window::key_callback(GLFWwindow *window, int key, int scancode, int action,
                          int mods)
{
    auto *self = static_cast<Window *>(glfwGetWindowUserPointer(window));
    self->key_callback(key, scancode, action, mods);
}

void Window::swap_buffers()
{
    glfwSwapBuffers(window_);
}
