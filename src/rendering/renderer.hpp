#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Renderer {
  public:
    bool inisialisasi();
    void clear();
    void render(glm::mat4 model, glm::mat4 view, glm::mat4 projection);
    void shutdown();
};

#endif // !RENDERER_HPP
