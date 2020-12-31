cmake_minimum_required(VERSION 3.17)
project(OpenGL)

set(CMAKE_CXX_STANDARD 20)

add_compile_definitions(GLEW_STATIC)

include_directories(Dependencies/GLFW/include)
include_directories(Dependencies/GLEW/include)
include_directories(src)
include_directories(src/vendor)
include_directories(src/vendor/glm)

link_directories(
        Dependencies/GLEW/lib/Release/x64
        Dependencies/GLFW/lib-vc2019
)

add_executable(
        OpenGL
        src/main.cpp
        src/Renderer/Renderer.cpp
        src/VertexBuffer/VertexBuffer.cpp
        src/IndexBuffer/IndexBuffer.cpp
        src/VertexArray/VertexArray.cpp
        src/VertexBufferLayout/VertexBufferLayout.cpp
        src/Types.h src/Shader/Shader.cpp
        src/GLDebug/GLDebug.cpp
        src/vendor/stb_image/stb_image.cpp
        src/Texture/Texture.cpp
        src/vendor/imgui/imgui.cpp
        src/vendor/imgui/imgui_draw.cpp
        src/vendor/imgui/imgui_impl_glfw_gl3.cpp
        src/Tests/TestClearColor.cpp
        src/Tests/Test.cpp
        src/Tests/TestTexture2D.cpp
)

target_link_libraries(OpenGL glew32s.lib glfw3.lib opengl32.lib)