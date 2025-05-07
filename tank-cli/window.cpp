#include <array>
#include <tank-cli/window.hpp>

std::unordered_map<GLFWwindow *, Window *> Window::forward_table;

void error_callback(int error, char const *description)
{
    spdlog::error("GLFW({}): {}", error, description);
}

void key_callback(GLFWwindow *window, int key, int scancode, int action,
                  int mods)
{
    Window::forward_table[window]->key_callback(key, scancode, action, mods);
}

void Window::initialize()
{
    glfwSetErrorCallback(error_callback);

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
    : window_{glfwCreateWindow(1600, 1200, "tank", nullptr, nullptr)}
{
    if (window_ == nullptr) {
        throw std::runtime_error{"Window or OpenGL context creation failed"};
    }

    forward_table.insert({window_, this});

    glfwSetKeyCallback(window_, ::key_callback);
    int width;
    int height;
    glfwGetFramebufferSize(window_, &width, &height);

    use();
    glfwSwapInterval(1);
    glViewport(0, 0, width, height);
}

Window::~Window()
{
    forward_table.erase(window_);
    glfwDestroyWindow(window_);
}

void Window::use() const
{
    glfwMakeContextCurrent(window_);
}

void Window::poll_events() const
{
    use();
    glfwPollEvents();
}

void Window::render() const
{
    use();
    glClear(GL_COLOR_BUFFER_BIT);
    // TODO: render follows here

    // glDeleteProgramPipelines

    // TODO: recover me
    // glfwSwapBuffers(_window);
}

bool Window::should_close() const
{
    return glfwWindowShouldClose(window_) != 0;
}
void Window::key_callback(int key, int /*scancode*/, int action, int /*mods*/)
{
    // Default: Press Esc to close the window.
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window_, GLFW_TRUE);
    }
}
void Window::set_should_close(bool value)
{
    glfwSetWindowShouldClose(window_, static_cast<int>(value));
}
