#pragma once

class Component_manager;
class Camera;
class Window;
class Shader_program;

namespace systems {
class Render {
  public:
    /// @param t Time since game started
    static void render(Component_manager &cm, Camera const &cam, Window &window,
                       Shader_program &player_shader,
                       Shader_program &env_shader, float t);
};
} // namespace systems
