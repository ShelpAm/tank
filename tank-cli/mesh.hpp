#pragma once

#include <cstdint>
#include <glad/gl.h>
#include <tank-cli/shader-program.hpp>
#include <vector>

// Now only support position of model
class Mesh {
  public:
    Mesh(Mesh const &) = delete;
    Mesh(Mesh &&) = delete;
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
                     static_cast<GLsizeiptr>(vertices.size() * sizeof(float)),
                     vertices.data(), GL_STATIC_DRAW);

        glGenBuffers(1, &ebo_);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
        glBufferData(
            GL_ELEMENT_ARRAY_BUFFER,
            static_cast<GLsizeiptr>(indices.size() * sizeof(std::uint32_t)),
            indices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                              nullptr);
        glEnableVertexAttribArray(0);

        // Unbind vao
        glBindVertexArray(0);
    }

    ~Mesh()
    {
        glDeleteVertexArrays(1, &vao_);
        glDeleteBuffers(1, &vbo_);
        glDeleteBuffers(1, &ebo_);
    }

    void render(Shader_program &shader) const
    {
        shader.use_program();
        glBindVertexArray(vao_);
        glDrawArrays(GL_TRIANGLES, 0,
                     static_cast<GLsizei>(vertices_.size() / 3));
        glBindVertexArray(0);
    }

  private:
    GLuint vao_{};
    GLuint vbo_{};
    GLuint ebo_{};
    std::vector<float> vertices_;
    std::vector<std::uint32_t> indices_;
};
