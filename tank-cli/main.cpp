#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <nlohmann/json.hpp>
#include <random>
#include <spdlog/spdlog.h>
#include <tank-cli/config.hpp>
#include <tank-cli/map.hpp>
#include <tank-cli/player.hpp>
#include <tank-cli/time.hpp>
#include <tank-cli/window.hpp>

int main(int argc, char **argv)
{
    using namespace std::chrono_literals;

    Config config(fs::path("config.json"));

    spdlog::set_level(config.log_level);

    spdlog::info("game started");

    Window::initialize();
    Window window;

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    char const *vertexShaderSource =
        "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        spdlog::error("ERROR::SHADER::VERTEX::COMPILATION_FAILED: {}", infoLog);
    }
    char const *fragmentShaderSource = R"(
#version 330 core
out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}
    )";
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        spdlog::error("ERROR::SHADER::VERTEX::COMPILATION_FAILED: {}", infoLog);
    }

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        spdlog::error("ERROR::SHADER::VERTEX::COMPILATION_FAILED: {}", infoLog);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    glUseProgram(shaderProgram);

    auto draw = [shaderProgram](std::array<float, 9> vertices) {
        unsigned int VAO;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        unsigned int indices[] = {0, 1, 2};

        unsigned int VBO;
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(),
                     GL_STATIC_DRAW);

        unsigned int EBO;
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
                     GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                              (void *)0);
        glEnableVertexAttribArray(0);

        glBindVertexArray(0);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    };

    auto draw_circle = [draw]() {};

    while (!window.should_close()) {
        window.render();
        draw({-1, 0, 0, 0, 1, 0, 1, 1, 0});
        glfwSwapBuffers(window.glfw_window());
        window.poll_events();
    }
    Window::deinitialize();

    constexpr int height = 40;
    constexpr int width = 60;
    Map map(height + 1, width + 1);
    map.add_barrier({.start = {0, 0}, .end = {0, width}});
    map.add_barrier({.start = {0, width}, .end = {height, width}});
    map.add_barrier({.start = {height, width}, .end = {height, 0}});
    map.add_barrier({.start = {height, 0}, .end = {0, 0}});
    map.add_barrier({.start = {0, width / 3}, .end{height / 3 * 2, width / 3}});
    map.add_barrier(
        {.start = {height / 3, width / 3 * 2}, .end{height, width / 3 * 2}});

    // map.add_barrier({.start = {5, 8}, .end = {25, 21}});

    auto last_update = Clock::now();
    auto last_draw = Clock::now();
    while (true) {
        // Seconds is the default time unit
        auto now = Clock::now();
        auto delta = now - last_update;
        float dt = std::chrono::duration<float>(delta).count();

        if (now - last_update >= 30ms) {
            last_update = now;
            map.update(dt);
        }

        if (now - last_draw >= 30ms) {
            last_draw = now;
            map.display_terrain();
        }
    }

    spdlog::info("closing game");

    return 0;
}
