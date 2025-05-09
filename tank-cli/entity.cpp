#include <random>
#include <spdlog/spdlog.h>
#include <tank-cli/entity.hpp>

glm::vec3 systems::util::yaw2vec(float yaw)
{
    return glm::vec3{std::cos(yaw), 0, -std::sin(yaw)};
}

void systems::Physics::update(ECS &ecs, float dt)
{
    for (Entity id : ecs.view<Transform>()) {
        auto const &trans = ecs.get<Transform>(id);
        auto const &pos = trans.position;
        spdlog::debug("systems::Physics entity {} .position: {} {} {}", id,
                      pos.x, pos.y, pos.z);
    }

    for (Entity id : ecs.view<Movement>()) {
        auto const &movement = ecs.get<Movement>(id);
        auto const &v = movement.velocity;
        auto const &d = movement.direction;
        spdlog::debug("systems::Physics entity {} direction: {}, velocity: {}",
                      id, d, v);
    }

    for (Entity id : ecs.view<Transform, Movement>()) {
        auto &trans = ecs.get<Transform>(id);
        auto &movement = ecs.get<Movement>(id);
        trans.position +=
            util::yaw2vec(movement.direction) * movement.velocity * dt;
    }
}

void systems::Spawner::update(ECS &ecs)
{
    int const desired_enemy_count = 5;
    int current = static_cast<int>(ecs.view<Enemy_tag>().size());

    for (int i = 0; i < desired_enemy_count - current; ++i) {
        spawn_enemy(ecs);
    }
}

void systems::Spawner::spawn_enemy(ECS &ecs)
{
    Entity id = ecs.make_entity();

    ecs.add(id, Transform{.position = {rand() % 10, 0.0f, rand() % 10}});
    ecs.add(id, Movement{.direction = 0, .velocity = 0});
    ecs.add(id, Enemy_tag{});

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
    Mesh tank(tank_vertices, tank_indices);
    ecs.add(id, Renderable{.mesh = std::move(tank)});
    ecs.get<Renderable>(id).mesh.render(systems::Resources::shader());
}

void systems::AI::update(ECS &ecs)
{
    std::random_device dev;
    std::mt19937 rng(dev());

    for (auto id : ecs.view<Enemy_tag>()) {
        spdlog::debug("systems::AI entity {} enemy_tag: true", id);
        auto &movement = ecs.get<Movement>(id);
        movement.velocity = rng() % 5;
    }

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

    for (auto id : ecs.view<Enemy_tag, Transform, Movement, Intent_to_fire>()) {
        auto &fire = ecs.get<Intent_to_fire>(id);
        auto &trans = ecs.get<Transform>(id);
        auto &movement = ecs.get<Movement>(id);

        auto bullet = ecs.make_entity();
        ecs.add(bullet,
                Transform{.position = trans.position +
                                      util::yaw2vec(movement.direction) * 1.F});
        ecs.add(bullet,
                Movement{.direction = movement.direction, .velocity = 30});
        ecs.add(bullet,
                Renderable{.mesh = Mesh(bullet_vertices, bullet_indices)});
    }
}

void systems::Render::render(ECS &ecs, Camera const &cam, Window const &window,
                             Shader_program &shader)
{
    for (auto id : ecs.view<Transform, Renderable>()) {
        spdlog::debug("systems::Render entity renderable: {}", id);
        auto &trans = ecs.get<Transform>(id);
        auto &renderable = ecs.get<Renderable>(id);
        glm::mat4 model(1);
        model = glm::translate(model, trans.position);
        glm::mat4 proj =
            glm::perspective(std::numbers::pi_v<float> / 4,
                             static_cast<float>(window.width()) /
                                 static_cast<float>(window.height()),
                             0.1F, 200.0F);
        shader.uniform_mat4("uMVP", proj * cam.calc_view_matrix() * model);
        renderable.mesh.render(shader);
    }
}
