#include <iostream>

#include "raylib.h"

#include "main.h"

int main()
{
    InitWindow(1080, 720, "Raylib works!");

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Hello, World!", 50, 100, 24, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

