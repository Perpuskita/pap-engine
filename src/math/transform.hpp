#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <glm/ext/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct Transform {
  glm::vec3 posisi {0.0f, 0.0f, 0.0f};
  glm::vec3 rotasi {0.0f, 0.0f, 0.0f};
  glm::vec3 skala {1.0f, 1.0f, 1.0f};

  glm::mat4 dapatkan_matrix() const {
    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, posisi);

    model = glm::rotate(model, rotasi.x, {1, 0, 0});
    model = glm::rotate(model, rotasi.y, {0, 1, 0});
    model = glm::rotate(model, rotasi.z, {0, 0, 1});

    model = glm::scale(model, skala);

    return model;
  }
};

#endif // !TRANSFORM_HPP
