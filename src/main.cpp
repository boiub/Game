#include <iostream>

#include "raylib.h"

#include "main.h"
#include "game_math.h"

struct Player
{
    Vector3 p;
    Vector3 dp;
};

float Square(float n) { return n*n; }

int main()
{
    InitWindow(1080, 720, "Raylib works!");

    Player player = {};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        float acceleration = 700;

        Vector3 ddp = {};

        if(IsKeyDown(KEY_W))
        {
            ddp.y -= acceleration;
        }
        if(IsKeyDown(KEY_A))
        {
            ddp.x -= acceleration;
        }
        if(IsKeyDown(KEY_S))
        {
            ddp.y += acceleration;
        }
        if(IsKeyDown(KEY_D))
        {
            ddp.x += acceleration;
        }

        float dt = GetFrameTime();

        ddp -= 7 * player.dp;
        player.dp += ddp*dt;
        player.p += 0.5f*ddp*dt*dt + player.dp*dt;

        DrawText("Hello, World!", 50, 100, 24, BLACK);
        Rectangle playerRec = {};
        playerRec.x = player.p.x;
        playerRec.y = player.p.y + player.p.z;
        playerRec.width = playerRec.height = 32;
        DrawRectangleRec(playerRec, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

