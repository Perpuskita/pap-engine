#include "input.hpp"
#include <GLFW/glfw3.h>

void Input::inisialisasi(void *handle_window) { window_handle = handle_window; }

void Input::update() {
  GLFWwindow *window = (GLFWwindow *)window_handle;

  state_keyboard[KEY_W] = glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS;
  state_keyboard[KEY_A] = glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS;
  state_keyboard[KEY_S] = glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS;
  state_keyboard[KEY_D] = glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS;
  state_keyboard[KEY_ESC] = glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS;

  state_mouse[MOUSE_KIRI] =
      glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
  state_mouse[MOUSE_KANAN] =
      glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS;

  glfwGetCursorPos(window, &posisi_mouse_x, &posisi_mouse_y);
}

bool Input::tombol_ditekan(TombolKeyboard tombol) {
  return state_keyboard[tombol];
}

bool Input::mouse_ditekan(TombolMouse mouse) { return state_mouse[mouse]; }

void Input::ambil_posisi_mouse(double &x, double &y) {
  x = posisi_mouse_x;
  y = posisi_mouse_y;
}
