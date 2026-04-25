#include "camera.hpp"
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera() : posisi(0.0f, 0.0f, 3.0f) {}

void Camera::set_posisi(const glm::vec3 &pos) { posisi = pos; }

glm::mat4 Camera::dapatkan_view_matrix() const {
  return glm::lookAt(posisi, glm::vec3(0.0f, 0.0f, 0.0f),
                     glm::vec3(0.0f, 1.0f, 0.0f));
}
