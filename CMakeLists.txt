cmake_minimum_required(VERSION 3.16)
project(papGame)

set(CMAKE_CXX_STANDARD 20)

find_package(glfw3 REQUIRED)

add_executable(papEngine
  src/main.cpp
  src/engine/mesin_engine.cpp
  src/sistem/window.cpp
)

target_link_libraries(papEngine glfw)
