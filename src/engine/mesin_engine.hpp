#ifndef MESIN_ENGINE_HPP
#define MESIN_ENGINE_HPP

#include "../sistem/window.hpp"
#include "../sistem/input.hpp"
#include "../rendering/renderer.hpp"
#include "../math/transform.hpp"
#include "../camera/camera.hpp"
#include <glm/gtc/matrix_transform.hpp>

class MesinGame {
  private:
    Window window;
    Input input;
    Renderer renderer;
    Camera camera;
    Transform transform;
    bool berjalan;

  public:
    bool inisialisasi();
    void jalankan();
    void shutdown();
    void status();
};

#endif // !MESIN_ENGINE_HPP
