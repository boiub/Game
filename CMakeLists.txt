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
        src/engine/Game.cpp
        src/engine/Game.h
        src/engine/renderer/Renderer.cpp
        src/engine/renderer/Renderer.h
        src/engine/scene/Scene.cpp
        src/engine/scene/Scene.h
        src/engine/gameObject/GameObject.cpp
        src/engine/gameObject/Component.cpp
        src/engine/gameObject/components/TransformComponent.h
        src/engine/gameObject/components/RenderableComponent.cpp
        src/engine/gameObject/components/RenderableComponent.h
        src/engine/scene/AssetManager.cpp
        src/engine/scene/AssetManager.h
        src/engine/scene/scenes/Scenes.h
        src/engine/scene/scenes/TestScene.cpp)

target_link_libraries(Game PRIVATE raylib)