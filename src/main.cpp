#include <chrono>
#include <filesystem>
#include <iostream>
#include <thread>

#include "raylib.h"

#include "game_api.h"
#include "main.h"

#ifdef _WIN32

#include <windows.h>

using Library = HMODULE;

Library LoadDynamicLibrary(const char *path)
{
    return LoadLibraryA(path);
}

void UnloadDynamicLibrary(Library lib)
{
    FreeLibrary(lib);
}

void *GetSymbol(Library lib, const char *name)
{
    return (void*)GetProcAddress(lib, name);
}

#else

#include <dlfcn.h>

using Library = void*;

Library LoadDynamicLibrary(const char *path)
{
    return dlopen(path, RTLD_NOW);
}

void UnloadDynamicLibrary(Library lib)
{
    dlclose(lib);
}

void *GetSymbol(Library lib, const char *name)
{
    return dlsym(lib, name);
}

#endif

int main()
{
#if defined(_WIN32)
    const char *gameLibPath = "Game.dll";
#elif defined(__APPLE__)
    const char *gameLibPath = "./Game.dylib";
#else
    const char *gameLibPath = "./Game.so";
#endif

    auto lastWriteTime = std::filesystem::last_write_time(gameLibPath);
    Library lib = LoadDynamicLibrary(gameLibPath);

    auto Init = (void(*)(GameState *))GetSymbol(lib, "GameInit");
    auto Update = (void(*)(GameState *))GetSymbol(lib, "GameUpdate");

    GameState gameState = {};
    Init(&gameState);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        auto currentWriteTime = std::filesystem::last_write_time(gameLibPath);
        if (currentWriteTime != lastWriteTime)
        {
            std::cout << "Reloading Game library... " << std::flush;

            lastWriteTime = currentWriteTime;

            UnloadDynamicLibrary(lib);
            lib = LoadDynamicLibrary(gameLibPath);

            Init = (void(*)(GameState *))GetSymbol(lib, "GameInit");
            Update = (void(*)(GameState *))GetSymbol(lib, "GameUpdate");

            std::cout << "DONE!" << std::endl;
        }

        float dt = GetFrameTime();
        Update(&gameState);
    }

    CloseWindow();
    return 0;
}

