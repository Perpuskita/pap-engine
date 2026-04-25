#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>

class Camera {
  private:
    glm::vec3 posisi;

public:
    Camera();
    void set_posisi(const glm::vec3& pos);
    glm::mat4 dapatkan_view_matrix() const;
};

#endif // !CAMERA_HPP
