#ifndef INPUT_HPP
#define INPUT_HPP

#include <unordered_map>
enum TombolKeyboard {
  KEY_W,
  KEY_A,
  KEY_S,
  KEY_D,
  KEY_ESC,
};

enum TombolMouse {
  MOUSE_KIRI,
  MOUSE_KANAN,
};

class Input {
private:
  void *window_handle;

  std::unordered_map<int, bool> state_keyboard;
  std::unordered_map<int, bool> state_mouse;

  double posisi_mouse_x;
  double posisi_mouse_y;

public:
  void inisialisasi(void *handle_window);

  void update();

  bool tombol_ditekan(TombolKeyboard tombol);
  bool mouse_ditekan(TombolMouse tombol);

  void ambil_posisi_mouse(double &x, double &y);
};

#endif // !INPUT_HPP
