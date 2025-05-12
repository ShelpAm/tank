#include <tank-cli/camera.hpp>
#include <tank-cli/ecs/component-manager.hpp>
#include <tank-cli/ecs/components.hpp>
#include <tank-cli/ecs/systems/render.hpp>
#include <tank-cli/mesh.hpp>
#include <tank-cli/shader-program.hpp>
#include <tank-cli/window.hpp>

void systems::Render::render(Component_manager &cm, Camera const &cam,
                             Window &window, Shader_program &player_shader,
                             Shader_program &env_shader, float t)
{
    window.use_window();
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    player_shader.uniform_1f("time", t);
    env_shader.uniform_1f("time", t);

    auto view = cam.calc_view_matrix();
    auto proj = glm::perspective(std::numbers::pi_v<float> / 4,
                                 static_cast<float>(window.width()) /
                                     static_cast<float>(window.height()),
                                 0.1F, 200.0F);

    for (auto id : cm.view<Transform, Renderable>()) {
        spdlog::trace("systems::Render entity renderable: {}", id);
        auto &t = cm.get<Transform>(id);
        auto &r = cm.get<Renderable>(id);
        glm::mat4 model(1);
        model = glm::translate(model, t.position);
        model = glm::rotate(model, t.yaw, {0, 1, 0});
        model = glm::scale(model, t.scale);
        if (cm.contains<Bot_tag>(id) || cm.contains<Player_tag>(id)) {
            player_shader.uniform_mat4("uMVP", proj * view * model);
            r.mesh->render(player_shader);
        }
        else if (cm.contains<Barrier_tag>(id)) {
            env_shader.uniform_mat4("uMVP", proj * view * model);
            r.mesh->render(env_shader);
        }
        else {
            env_shader.uniform_mat4("uMVP", proj * view * model);
            r.mesh->render(env_shader);
        }
    }

    window.swap_buffers();
    window.poll_events();
}
