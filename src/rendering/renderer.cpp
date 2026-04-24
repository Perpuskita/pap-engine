#include "renderer.hpp"
#include <GL/glew.h>
#include <iostream>

static unsigned int VAO, VBO;
static unsigned int shader_program;

static const char *vertex_shader_src = R"(
#version 330 core
layout (location = 0) in vec3 posisi;

void main() {
  gl_Position = vec4(posisi, 1.0);
}
)";

static const char *fragment_shader_src = R"(
#version 330 core
out vec4 warna;

void main() {
  warna = vec4(1.0, 0.5, 0.2, 1.0);
}
)";

unsigned int compile_shader(unsigned int type, const char *src) {
  unsigned int shader = glCreateShader(type);
  glShaderSource(shader, 1, &src, nullptr);
  glCompileShader(shader);

  int success;
  char info[512];
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader, 512, nullptr, info);
    std::cerr << "Shader error: " << info << "\n";
  }

  return shader;
}

bool Renderer::inisialisasi() {
  if (glewInit() != GLEW_OK) {
    std::cerr << "GLEW gagal inisialisasi\n";
    return false;
  }

  float vertices[] = {
    0.0f,
    0.5f,
    0.0f,
    -0.5f,
    -0.5f,
    0.0f,
    0.5f,
    -0.5f,
    0.0f,
  };

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  unsigned int vs = compile_shader(GL_VERTEX_SHADER, vertex_shader_src);
  unsigned int fs = compile_shader(GL_FRAGMENT_SHADER, fragment_shader_src);

  shader_program = glCreateProgram();
  glAttachShader(shader_program, vs);
  glAttachShader(shader_program, fs);
  glLinkProgram(shader_program);

  glDeleteShader(vs);
  glDeleteShader(fs);

  return true;
}

void Renderer::clear() {
  glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::render() {
  glUseProgram(shader_program);
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Renderer::shutdown() {
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
}
