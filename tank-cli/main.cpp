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
#include <tank-cli/ecs/world.hpp>
#include <tank-cli/glfw.hpp>
#include <tank-cli/map.hpp>
#include <tank-cli/mesh.hpp>
#include <tank-cli/motion.hpp>
#include <tank-cli/player.hpp>
#include <tank-cli/shader-program.hpp>
#include <tank-cli/time.hpp>
#include <tank-cli/window.hpp>

// Data (models) BEGIN--------------------
std::vector<glm::vec3> bullet_vertices = {
    {-0.5f, -0.5f, -0.5f}, {0.5f, -0.5f, -0.5f}, {0.5f, 0.5f, -0.5f},
    {-0.5f, 0.5f, -0.5f},  {-0.5f, -0.5f, 0.5f}, {0.5f, -0.5f, 0.5f},
    {0.5f, 0.5f, 0.5f},    {-0.5f, 0.5f, 0.5f}};

std::vector<uint32_t> bullet_indices = {
    0, 1, 2, 2, 3, 0, // front face
    4, 5, 6, 6, 7, 4, // back face
    7, 3, 0, 0, 4, 7, // left face
    6, 2, 1, 1, 5, 6, // right face
    0, 1, 5, 5, 4, 0, // bottom face
    3, 2, 6, 6, 7, 3  // top face
};

// 厚度
float h = 3.0F;
std::vector<glm::vec3> tank_vertices = {
    {6, h, 3}, {-6, h, 3}, {6, h, -3}, {-6, h, -3}, {0, h, 1},  {0, h, -1},
    {9, h, 1}, {9, h, -1}, {6, 0, 3},  {-6, 0, 3},  {6, 0, -3}, {-6, 0, -3},
    {0, 0, 1}, {0, 0, -1}, {9, 0, 1},  {9, 0, -1}};
std::vector<uint32_t> tank_indices = {
    0,  1,  2,  1,  3,  2,  4,  5, 6,  5,  7, 6, 10, 9,  8, 10, 11, 9,
    14, 13, 12, 14, 15, 13, 8,  9, 0,  0,  9, 1, 9,  11, 1, 1,  11, 3,
    11, 10, 3,  3,  10, 2,  10, 8, 2,  2,  8, 0, 12, 14, 4, 4,  14, 6,
    13, 5,  15, 15, 5,  7,  12, 4, 13, 13, 4, 5, 14, 15, 6, 6,  15, 7,
};
// Data END----------------

int main(int argc, char **argv)
{
    using namespace std::chrono_literals;

    Config config(fs::path("config.json"));
    spdlog::set_level(config.log_level);

    spdlog::info("game started");

    Window::initialize();
    {
#define USE_ECS
#ifndef USE_ECS
        Window window;
        Shader_program player_shader("shader/main.vert", "shader/player.frag");
        Shader_program shader("shader/main.vert", "shader/main.frag");
#else
        Window &window = systems::Resources::main_window();
        Shader_program &player_shader = systems::Resources::player_shader();
        Shader_program &env_shader = systems::Resources::env_shader();
#endif

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glEnable(GL_DEPTH_TEST);
        glClearColor(0.2, 0.2, 0.2, 1);

        Mesh tank(tank_vertices, tank_indices);
        Mesh bullet(bullet_vertices, bullet_indices);

        constexpr int width = 80;
        constexpr int height = 60;
#ifndef USE_ECS
        Map map(width + 1, height + 1);
#else
        Map &map = systems::Resources::map();
#endif

#if 0
        Camera camera(std::numbers::pi / 2, (-std::numbers::pi / 2) + 0.01F,
                      glm::vec3(map.fwidth() / 2, 100, map.fheight() / 2));
#else
        Camera camera(
            std::numbers::pi / 2, (-std::numbers::pi / 3.5) + 0.01F,
            glm::vec3(map.fwidth() / 2, 100 - 30, map.fheight() / 2 + 60));
#endif

        glm::mat4 view = camera.calc_view_matrix();
        bool use_tank_camera = false;

        glm::mat4 proj = glm::perspective(
            glm::radians(45.0F),
            static_cast<float>(window.width()) / window.height(), 0.1F, 200.0F);

        auto render_barrier = [&](Barrier const &b) {
            glm::mat4 model(1);

            glm::mat4 mvp = proj * view * model;
            env_shader.uniform_mat4("uMVP", mvp);

            // 挤出一半厚度和一半高度
            constexpr float halfWidth = 0.5F;
            constexpr float halfHeight = 3.2F;

            // 1. 计算中心线的两个端点
            glm::vec3 s(b.start.x, 0, b.start.y);
            glm::vec3 e(b.end.x, 0, b.end.y);

            // 2. 计算宽度方向单位向量（水平面内法线）
            glm::vec3 dir = glm::normalize(e - s);
            glm::vec3 right = glm::normalize(glm::cross(dir, {0, 1, 0}));

            // 3. 在“底面”和“顶面”两个高度层上，各生成 4 个顶点
            std::vector<glm::vec3> barrier_verts = {
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

            Mesh barrier(barrier_verts, barrier_idx);
            barrier.render(env_shader);
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

        World world;

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
                        if (e.key == GLFW_KEY_Q && e.action == GLFW_PRESS) {
                            use_tank_camera = !use_tank_camera;
                        }
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
            spdlog::debug("current time since game started: {}", t);
            // env_shader.uniform_1f("time", t);
            // player_shader.uniform_1f("time", t);
            glm::vec3 const center{map.fwidth() / 2, 50, map.fheight() / 2};
            if (use_tank_camera) {
                if (map.players_.empty()) {
                    continue;
                }
                Camera tank_camera(map.players_.front().fdirection(), -0.2F,
                                   map.players_.front().position() -
                                       2.F * map.players_.front().direction() +
                                       glm::vec3{0, 1.51F, 0});
                view = tank_camera.calc_view_matrix();
            }
            else {
                auto look_at = [&](glm::vec3 eye, glm::vec3 target) {
                    auto to_target = target - eye;
                    auto to_center = center - eye;
                    auto right = glm::cross(to_target, to_center);
                    auto up = glm::normalize(glm::cross(right, to_target));
                    return glm::lookAt(eye, target, up);
                };
                view = look_at(
                    center +
                        glm::vec3{map.fwidth() * 3 / 4 * std::cos(t * 0.1),
                                  map.fheight() * 1.5,
                                  -map.fheight() * 3 / 4 * std::sin(t * 0.1)},
                    {map.fwidth() / 2, 0, map.fheight() / 2});
            }

            // if (now - last_render >= 30ms) {
            last_render = now;

#ifndef USE_ECS
            map.render(shader, player_shader, render_barrier);
#else
            world.update(dt, t); // TODO(shelpam): Integrating
#endif
            // }
        }
    }
    Window::deinitialize();

    spdlog::info("closing game");

    return 0;
}
