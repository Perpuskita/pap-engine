#ifndef MESIN_ENGINE_HPP
#define MESIN_ENGINE_HPP

#include "../sistem/window.hpp"

class MesinGame {
  private:
    Window window;
    bool berjalan;

  public:
    bool inisialisasi();
    void jalankan();
    void shutdown();
};

#endif // !MESIN_ENGINE_HPP
