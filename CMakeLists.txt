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
        src/main.h)

target_link_libraries(Game raylib)

add_library(GameLib SHARED
    src/game.cpp
)

target_link_libraries(GameLib raylib)

set_target_properties(GameLib PROPERTIES
    PREFIX ""
    OUTPUT_NAME "Game"
)

add_custom_command(TARGET GameLib POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:GameLib>
    $<TARGET_FILE_DIR:Game>
)

add_dependencies(Game GameLib)
