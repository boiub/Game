cmake_minimum_required(VERSION 4.1)
project(Game)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(Game
        src/main.cpp
        src/main.h)
