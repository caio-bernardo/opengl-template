cmake_minimum_required(VERSION  3.10)
project(OpenGLTemplate)

set(CMAKE_CXX_STANDARD 20)

add_executable(opengl_template src/main.cpp glad/src/glad.c)

target_include_directories(opengl_template PRIVATE glad/include)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(opengl_template PRIVATE OpenGL::GL glfw)
