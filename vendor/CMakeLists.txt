cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

find_package(OpenGL REQUIRED)

add_subdirectory("GLFW")
add_subdirectory("glm")
add_subdirectory("spdlog")
include_directories("spdlog/include")

add_library(glad "glad/src/glad.c")
target_include_directories(glad PUBLIC "glad/include")

target_compile_definitions(spdlog INTERFACE
  SPDLOG_BUILD_WARNINGS OFF
)

target_link_libraries(Core PUBLIC
  OpenGL::GL
  opengl32.lib
  glfw
  glad
  glm
  spdlog
)
