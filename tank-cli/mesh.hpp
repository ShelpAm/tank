#pragma once

#include <cassert>
#include <cstdint>
#include <glad/gl.h>
#include <tank-cli/shader-program.hpp>
#include <vector>

// For rendering, containing vertices of models, vao, vbo and ebo.
//
// Now only support position of model
class Mesh {
  public:
    Mesh(Mesh const &) = delete;
    Mesh(Mesh &&other) noexcept
        : vao_(other.vao_), vbo_(other.vbo_), ebo_(other.ebo_),
          vertices_(std::move(other.vertices_)),
          indices_(std::move(other.indices_))

    {
        other.vao_ = other.vbo_ = other.ebo_ = -1U;
    }
    Mesh &operator=(Mesh const &) = delete;
    Mesh &operator=(Mesh &&) = delete;
    Mesh(std::vector<float> vertices, std::vector<std::uint32_t> indices)
        : vertices_(std::move(vertices)), indices_(std::move(indices))
    {
        glGenVertexArrays(1, &vao_);
        glBindVertexArray(vao_);

        // vbo and ebo are all bound to vao
        glGenBuffers(1, &vbo_);
        glBindBuffer(GL_ARRAY_BUFFER, vbo_);
        glBufferData(GL_ARRAY_BUFFER,
                     static_cast<GLsizeiptr>(vertices_.size() * sizeof(float)),
                     vertices_.data(), GL_STATIC_DRAW);

        glGenBuffers(1, &ebo_);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
        glBufferData(
            GL_ELEMENT_ARRAY_BUFFER,
            static_cast<GLsizeiptr>(indices_.size() * sizeof(std::uint32_t)),
            indices_.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                              nullptr);
        glEnableVertexAttribArray(0);

        // Unbind vao
        glBindVertexArray(0);

        assert(vao_ != -1U);
        assert(vbo_ != -1U);
        assert(ebo_ != -1U);

        GLenum err;
        while ((err = glGetError()) != GL_NO_ERROR) {
            throw std::runtime_error(
                std::format("Mesh::Mesh OpenGL error: {}", err));
        }
    }
    Mesh(std::vector<glm::vec3> vertices, std::vector<std::uint32_t> indices)
        : Mesh(
              // Converts to std::vector<float>
              [&vertices]() {
                  std::vector<float> verts(vertices.size() * 3);
                  for (int i{}; i != vertices.size(); ++i) {
                      verts[(3 * i) + 0] = vertices[i].x;
                      verts[(3 * i) + 1] = vertices[i].y;
                      verts[(3 * i) + 2] = vertices[i].z;
                  }
                  return verts;
              }(),
              std::move(indices))
    {
    }

    ~Mesh()
    {
        if (vao_ != -1U) {
            glDeleteVertexArrays(1, &vao_);
        }
        if (vbo_ != -1U) {
            glDeleteBuffers(1, &vbo_);
        }
        if (ebo_ != -1U) {
            glDeleteBuffers(1, &ebo_);
        }
    }

    void render(Shader_program const &shader) const
    {
        shader.use_program();
        glBindVertexArray(vao_);
        glDrawElements(GL_TRIANGLES, static_cast<GLint>(indices_.size()),
                       GL_UNSIGNED_INT, nullptr);
        glBindVertexArray(0);

        {
            shader.use_program();

            glBindVertexArray(vao_);

            // Debug
            spdlog::debug("Rendering mesh: vao={}, indices={}", vao_,
                          indices_.size());
            GLint current_vao{-1};
            glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &current_vao);
            spdlog::debug("Currently bound VAO: {}", current_vao);

            glDrawElements(GL_TRIANGLES, static_cast<GLint>(indices_.size()),
                           GL_UNSIGNED_INT, nullptr);

            assert(indices_.size() != 0);

            GLenum err;
            while ((err = glGetError()) != GL_NO_ERROR) {
                throw std::runtime_error(
                    std::format("OpenGL error in Mesh::render(): {}", err));
            }

            glBindVertexArray(0);
        }
    }

    [[nodiscard]] auto const &vertices() const
    {
        return vertices_;
    }

    [[nodiscard]] auto const &indices() const
    {
        return indices_;
    }

  private:
    // Initial invalid value for error checking: if it's -1U (very big signed),
    // then it indicates an error or the Mesh object doesn't own the model.
    GLuint vao_{-1U};
    GLuint vbo_{-1U};
    GLuint ebo_{-1U};
    std::vector<float> vertices_;
    std::vector<std::uint32_t> indices_;
};
