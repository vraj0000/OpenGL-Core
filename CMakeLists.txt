cmake_minimum_required(VERSION 3.24.2)

set(CMAKE_CXX_FLAGS "-Wall -lGL -ldl -lglfw")

project(OpenGL_Test VERSION 1)

add_executable(OpenGL_Test test.cpp)



add_subdirectory(Include)
target_link_libraries(OpenGL_Test PUBLIC main glad App Texture VertexBuffer IndexBuffer Shaders Camera)


add_subdirectory(Include/imgui)
target_link_libraries(OpenGL_Test PUBLIC imgui imgui_demo imgui_draw imgui_impl_glfw imgui_impl_opengl3 imgui_tables imgui_widgets)
