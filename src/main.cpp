#include "engine/mesin_engine.hpp"
#include <iostream>

int main() {
  MesinGame mesin;

  if (!mesin.inisialisasi()) {
    std::cerr << "gagal untuk jalankan enginenya wak\n";
    return -1;
  }

  mesin.jalankan();
  mesin.shutdown();

  return 0;
}
