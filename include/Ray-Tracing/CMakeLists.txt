cmake_minimum_required(VERSION 3.24.2)

project(Ray-Tracing)

add_executable(${PROJECT_NAME} image.cpp)
add_subdirectory(imgui)