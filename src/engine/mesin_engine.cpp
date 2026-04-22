#include "mesin_engine.hpp"
#include <iostream>

bool MesinGame::inisialisasi() {
  window.lebar = 800;
  window.tinggi = 600;
  window.judul = "Pap Game";

  if (!window.inisialisasi()) {
    return false;
  }

  berjalan = true;
  return true;
}

void MesinGame::jalankan() {
  while (berjalan && !window.harus_tutup()) {
    // TODO: untuk update dan render
    window.update();
  }
}

void MesinGame::shutdown() { window.shutdown(); }
