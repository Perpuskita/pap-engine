#ifndef WINDOW_HPP
#define WINDOW_HPP

struct Window {
  int lebar;
  int tinggi;
  const char* judul;

  void* handle;

  bool inisialisasi();
  void update();
  bool harus_tutup();
  void shutdown();
};

#endif // !WINDOW_HPP
