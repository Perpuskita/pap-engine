#include "mesin_engine.hpp"
#include <iostream>

bool MesinGame::inisialisasi() {
  window.lebar = 800;
  window.tinggi = 600;
  window.judul = "Pap Game";

  if (!window.inisialisasi()) {
    return false;
  }

  input.inisialisasi(window.handle);

  berjalan = true;
  return true;
}

void MesinGame::jalankan() {
  while (berjalan && !window.harus_tutup()) {

    input.update();

    if (input.tombol_ditekan(KEY_W)) {
      std::cout << "tombol dari w ditekan\n";
    }

    if (input.tombol_ditekan(KEY_A)) {
      std::cout << "tombol dari a ditekan\n";
    }

    if (input.tombol_ditekan(KEY_S)) {
      std::cout << "tombol dari s ditekan\n";
    }

    if (input.tombol_ditekan(KEY_D)) {
      std::cout << "tombol dari d ditekan\n";
    }

    if (input.tombol_ditekan(KEY_ESC)) {
      std::cout << "keluar dari program\n";
      berjalan = false;
    }

    if (input.mouse_ditekan(MOUSE_KIRI)) {
      std::cout << "klik mouse kiri\n";
    }

    if (input.mouse_ditekan(MOUSE_KANAN)) {
      std::cout << "klik mouse kanan\n";
    }

    double x, y;
    input.ambil_posisi_mouse(x, y);
    std::cout << "posisi mouse x: " << x << " y: " << y << "\n";

    // TODO: untuk update dan render
    window.update();
  }
}

void MesinGame::shutdown() { window.shutdown(); }
