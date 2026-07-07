cmake_minimum_required(VERSION 4.1)
project(Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)

include(FetchContent)

FetchContent_Declare(
        raylib
        DOWNLOAD_EXTRACT_TIMESTAMP OFF
        URL https://github.com/raysan5/raylib/archive/refs/tags/6.0.tar.gz
        FIND_PACKAGE_ARGS
)

FetchContent_MakeAvailable(raylib)

add_executable(Game
        src/main.cpp
        src/main.h
        src/engine/main/Game.cpp
        src/engine/main/Game.h
        src/engine/main/renderer/Renderer.cpp
        src/engine/main/renderer/Renderer.h
        src/engine/main/scene/Scene.cpp
        src/engine/main/scene/Scene.h
        src/engine/gameObject/GameObject.cpp
        src/engine/gameObject/Component.cpp
        src/engine/gameObject/components/TransformComponent.h)

target_link_libraries(Game PRIVATE raylib)