#include "tank-cli/motion.hpp"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <nlohmann/json.hpp>
#include <numbers>
#include <random>
#include <ranges>
#include <spdlog/spdlog.h>
#include <tank-cli/camera.hpp>
#include <tank-cli/config.hpp>
#include <tank-cli/glfw.hpp>
#include <tank-cli/map.hpp>
#include <tank-cli/mesh.hpp>
#include <tank-cli/player.hpp>
#include <tank-cli/shader-program.hpp>
#include <tank-cli/time.hpp>
#include <tank-cli/window.hpp>

int main(int argc, char **argv)
{
    // Data (models) BEGIN--------------------
    std::vector<float> bullet_vertices = {
        -0.5f, -0.5f, -0.5f, 0.5f,  -0.5f, -0.5f, 0.5f,  0.5f,  -0.5f, 0.5f,
        0.5f,  -0.5f, -0.5f, 0.5f,  -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
        0.5f,  0.5f,  -0.5f, 0.5f,  0.5f,  0.5f,  0.5f,  0.5f,  0.5f,  0.5f,
        -0.5f, 0.5f,  0.5f,  -0.5f, -0.5f, 0.5f,  -0.5f, 0.5f,  0.5f,  -0.5f,
        0.5f,  -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
        0.5f,  -0.5f, 0.5f,  0.5f,  0.5f,  0.5f,  0.5f,  0.5f,  0.5f,  -0.5f,
        0.5f,  -0.5f, -0.5f, 0.5f,  -0.5f, -0.5f, 0.5f,  -0.5f, 0.5f,  0.5f,
        0.5f,  0.5f,  -0.5f, -0.5f, -0.5f, 0.5f,  -0.5f, -0.5f, 0.5f,  -0.5f,
        0.5f,  0.5f,  -0.5f, 0.5f,  -0.5f, -0.5f, 0.5f,  -0.5f, -0.5f, -0.5f,
        -0.5f, 0.5f,  -0.5f, 0.5f,  0.5f,  -0.5f, 0.5f,  0.5f,  0.5f,  0.5f,
        0.5f,  0.5f,  -0.5f, 0.5f,  0.5f,  -0.5f, 0.5f,  -0.5f};
    assert(bullet_vertices.size() == 36 * 3);

    // 厚度
    float h = 3.0F;

    std::vector<glm::vec3> tank_vertices = {
        {6, h, 3}, {-6, h, 3}, {6, h, -3}, {-6, h, -3}, {0, h, 1},  {0, h, -1},
        {9, h, 1}, {9, h, -1}, {6, 0, 3},  {-6, 0, 3},  {6, 0, -3}, {-6, 0, -3},
        {0, 0, 1}, {0, 0, -1}, {9, 0, 1},  {9, 0, -1}};

    // 拆成：
    //  • 顶面   (两组三角形)
    //  • 底面   (同样的两组，但反向绕序)
    //  • 侧面   每条边两个三角形，共 8 条边 → 16 个三角
    std::vector<uint32_t> tank_indices = {
        0,  1,  2,  1,  3,  2,  4,  5, 6,  5,  7, 6, 10, 9,  8, 10, 11, 9,
        14, 13, 12, 14, 15, 13, 8,  9, 0,  0,  9, 1, 9,  11, 1, 1,  11, 3,
        11, 10, 3,  3,  10, 2,  10, 8, 2,  2,  8, 0, 12, 14, 4, 4,  14, 6,
        13, 5,  15, 15, 5,  7,  12, 4, 13, 13, 4, 5, 14, 15, 6, 6,  15, 7,
    };
    // Data END----------------

    using namespace std::chrono_literals;

    Config config(fs::path("config.json"));

    spdlog::set_level(config.log_level);

    spdlog::info("game started");

    Window::initialize();
    {
        Window window;

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        Shader_program player_shader("shader/main.vert", "shader/player.frag");
        Shader_program shader("shader/main.vert", "shader/main.frag");
        auto advanced_draw = [](Shader_program &shader,
                                std::vector<glm::vec3> const &vertices,
                                std::vector<std::uint32_t> const &indices) {
            unsigned int VAO;
            glGenVertexArrays(1, &VAO);
            glBindVertexArray(VAO);

            unsigned int VBO;
            glGenBuffers(1, &VBO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3),
                         vertices.data(), GL_STATIC_DRAW);

            unsigned int EBO;
            glGenBuffers(1, &EBO);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                         indices.size() * sizeof(std::uint32_t), indices.data(),
                         GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                                  (void *)0);
            glEnableVertexAttribArray(0);

            glBindVertexArray(0);

            shader.use_program();
            glBindVertexArray(VAO);
            glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT,
                           nullptr);
            glBindVertexArray(0);

            glDeleteVertexArrays(1, &VAO);
            glDeleteBuffers(1, &VBO);
            glDeleteBuffers(1, &EBO);
        };

        auto draw = [](Shader_program &shader,
                       std::vector<float> const &vertices) {
            unsigned int VAO;
            glGenVertexArrays(1, &VAO);
            glBindVertexArray(VAO);

            unsigned int VBO;
            glGenBuffers(1, &VBO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
                         vertices.data(), GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                                  (void *)0);
            glEnableVertexAttribArray(0);

            glBindVertexArray(0);

            shader.use_program();
            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 3);
            glBindVertexArray(0);

            glDeleteVertexArrays(1, &VAO);
            glDeleteBuffers(1, &VBO);
        };

        constexpr int width = 80;
        constexpr int height = 60;
        Map map(width + 1, height + 1);

#if 1
        Camera camera(std::numbers::pi / 2, (-std::numbers::pi / 2) + 0.01F,
                      glm::vec3(map.fwidth() / 2, 100, map.fheight() / 2));
#else
        Camera camera(
            std::numbers::pi / 2, (-std::numbers::pi / 3.5) + 0.01F,
            glm::vec3(map.fwidth() / 2, 100, map.fheight() / 2 + 100));
#endif

        glm::mat4 view = camera.calc_view_matrix();
#define USE_TANK_CAMERA

        glm::mat4 proj = glm::perspective(glm::radians(45.0F),
                                          static_cast<float>(window.width()) /
                                              window.height(),
                                          0.1F, 1000.0F);

        std::vector<float> tank_vertices_float(tank_vertices.size() * 3);
        std::ranges::copy(&tank_vertices.data()->x, &tank_vertices.back().z + 1,
                          tank_vertices_float.begin());
        Mesh tank_mesh(tank_vertices_float, tank_indices);

        auto render_player = [&, draw, advanced_draw](Shader_program &shader,
                                                      Player const &p,
                                                      bool is_bullet = false) {
            spdlog::trace("render_player");
            auto pos = p.position();

            glm::mat4 model(1);
            model = glm::translate(model, pos);
            model = glm::rotate(model, p.fdirection(), {0, 1, 0});
            model = glm::scale(model, glm::vec3(0.15));

#ifdef USE_TANK_CAMERA
            if (map.players_.empty()) {
                return;
            }
            Camera tank_camera(map.players_.front().fdirection(), -0.2F,
                               map.players_.front().position() -
                                   2.F * map.players_.front().direction() +
                                   glm::vec3{0, 1.51F, 0});
            view = tank_camera.calc_view_matrix();
#endif

            glm::mat4 mvp = proj * view * model;
            shader.use_program();
            shader.uniform_mat4("uMVP", mvp);

            assert(!is_bullet);

            advanced_draw(shader, tank_vertices, tank_indices);
            // tank_mesh.render(shader);
        };

        auto render_bullet = [&](Shader_program &shader, Bullet b) {
            auto pos = b.position;
            spdlog::trace("render_bullet: dir: {} {} {}", b.direction.x,
                          b.direction.y, b.direction.z);

#ifdef USE_TANK_CAMERA
            if (map.players_.empty()) {
                return;
            }
            Camera tank_camera(map.players_.front().fdirection(), -0.2F,
                               map.players_.front().position() -
                                   2.F * map.players_.front().direction() +
                                   glm::vec3{0, 1.51F, 0});
            view = tank_camera.calc_view_matrix();
#endif

            glm::mat4 model(1);
            model = glm::translate(model, pos);
            // model = glm::rotate(model, p.fdirection(), {0, 1, 0});
            model = glm::scale(model, glm::vec3(0.15));

            // Camera tank_camera(map.players_.front().fdirection(), -0.2F,
            //                    map.players_.front().position() -
            //                        2.F * map.players_.front().direction() +
            //                        glm::vec3{0, 1.51F, 0});
            // view = tank_camera.calc_view_matrix();

            glm::mat4 mvp = proj * view * model;
            shader.use_program();
            shader.uniform_mat4("uMVP", mvp);

            draw(shader, bullet_vertices);
        };

        auto render_barrier = [&shader, &proj, &view, &map, draw,
                               advanced_draw](Barrier const &b) {
            glm::mat4 model(1);

#ifdef USE_TANK_CAMERA
            if (map.players_.empty()) {
                return;
            }
            Camera tank_camera(map.players_.front().fdirection(), -0.2F,
                               map.players_.front().position() -
                                   2.F * map.players_.front().direction() +
                                   glm::vec3{0, 1.51F, 0});
            view = tank_camera.calc_view_matrix();
#endif

            glm::mat4 mvp = proj * view * model;
            shader.use_program();
            shader.uniform_mat4("uMVP", mvp);

            // 挤出一半厚度和一半高度
            constexpr float halfWidth = 0.5f;
            constexpr float halfHeight = 0.2f;

            // 1. 计算中心线的两个端点
            glm::vec3 s(b.start.x, 0, b.start.y);
            glm::vec3 e(b.end.x, 0, b.end.y);

            // 2. 计算宽度方向单位向量（水平面内法线）
            glm::vec3 dir = glm::normalize(e - s);
            glm::vec3 right = glm::normalize(glm::cross(dir, {0, 1, 0}));

            // 3. 在“底面”和“顶面”两个高度层上，各生成 4 个顶点
            std::array<glm::vec3, 8> barrier_verts = {
                // 底面 (y = -halfHeight)
                s + right * halfWidth + glm::vec3{0, -halfHeight, 0},
                s - right * halfWidth + glm::vec3{0, -halfHeight, 0},
                e + right * halfWidth + glm::vec3{0, -halfHeight, 0},
                e - right * halfWidth + glm::vec3{0, -halfHeight, 0},
                // 顶面 (y = +halfHeight)
                s + right * halfWidth + glm::vec3{0, halfHeight, 0},
                s - right * halfWidth + glm::vec3{0, halfHeight, 0},
                e + right * halfWidth + glm::vec3{0, halfHeight, 0},
                e - right * halfWidth + glm::vec3{0, halfHeight, 0},
            };

            // 4. 用 12 个三角形（6 个面 × 2 三角形）把这个“盒子”画出来
            std::vector<std::uint32_t> barrier_idx = {
                0, 1, 2, 1, 3, 2, 4, 6, 5, 5, 6, 7, 0, 2, 4, 4, 2, 6,
                2, 3, 6, 6, 3, 7, 3, 1, 7, 7, 1, 5, 1, 0, 5, 5, 0, 4};

            // 6. 调用高级绘制函数
            advanced_draw(shader,
                          std::vector<glm::vec3>(barrier_verts.begin(),
                                                 barrier_verts.end()),
                          barrier_idx);
        };

        map.add_barrier({.start = {0, 0}, .end = {width, 0}});
        map.add_barrier({.start = {width, 0}, .end = {width, height}});
        map.add_barrier({.start = {width, height}, .end = {0, height}});
        map.add_barrier({.start = {0, height}, .end = {0, 0}});
        map.add_barrier(
            {.start = {width / 3, 0}, .end = {width / 3, height / 3 * 2}});
        map.add_barrier({.start = {width / 3 * 2, height / 3},
                         .end = {width / 3 * 2, height}});

        // Lock
        // map.add_barrier(
        //     {.start = glm::vec3{-1, 0, 0}, .end = glm::vec3{-2, 0, 0}});

        std::unordered_map<int, bool> key_pressing;

        auto start_time = Clock::now();
        auto last_update = Clock::now();
        auto last_render = Clock::now();

        std::size_t tick{};
        while (!window.should_close()) {
            spdlog::trace("tick {}", tick++);

            // Seconds is the default time unit
            auto now = Clock::now();
            auto delta = now - last_update;
            float dt = std::chrono::duration<float>(delta).count();

            // Process input
            auto events = window.take_events();
            for (auto const &e : events) {
                std::visit(
                    [&](Key_event e) {
                        spdlog::info("key: key {} action {}", e.key, e.action);
                        // Press Esc to close the window.
                        if (e.key == GLFW_KEY_ESCAPE &&
                            e.action == GLFW_PRESS) {
                            window.set_should_close(true);
                            return;
                        }
                        key_pressing[e.key] =
                            e.action == GLFW_PRESS || e.action == GLFW_REPEAT;
                    },
                    e);
            }
            // if (now - last_update >= 30ms) {
            last_update = now;
            if (!map.players_.empty()) {
                map.players_.front().set_rotation_speed(
                    std::numbers::pi / 4 * 8 *
                    (key_pressing[GLFW_KEY_A] - key_pressing[GLFW_KEY_D]));
                map.players_.front().set_velocity(
                    key_pressing[GLFW_KEY_W] == key_pressing[GLFW_KEY_S] ? 0
                    : key_pressing[GLFW_KEY_W]                           ? 20
                                                                         : -16);
                map.players_.front().set_should_fire(key_pressing[GLFW_KEY_J]);
            }
            map.update(dt);
            // }

            float t = Durationf(now - start_time).count();
            shader.uniform_1f("time", t);
            player_shader.uniform_1f("time", t);
            window.set_render_fn([&]() {
                map.render(shader, player_shader, render_player, render_bullet,
                           render_barrier);
            });

            // if (now - last_draw >= 30ms)
            {
                last_render = now;

                window.render();
            }
        }
    }
    Window::deinitialize();

    spdlog::info("closing game");

    return 0;
}
