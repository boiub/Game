#include <iostream>
#include <math.h>

#include "raylib.h"

#include "main.h"
#include "game_math.h"

struct Player
{
    Vector3 p;
    Vector3 dp;
};

Vector2 ProjectPoint(Vector3 p, float angle)
{
    Vector2 rtn;

    rtn.x = p.x;
    rtn.y = cosf(angle) * p.y - sinf(angle) * p.z;

    return rtn;
}

Rectangle RecBottomCenterWidthHeight(Vector2 bottomCenter, Vector2 widthHeight)
{
    Vector2 topLeft;
    topLeft.x = bottomCenter.x - 0.5 * widthHeight.x;
    topLeft.y = bottomCenter.y - widthHeight.y;

    return Rectangle { topLeft.x, topLeft.y, widthHeight.x, widthHeight.y };
}

int main()
{
    InitWindow(1080, 720, "Raylib works!");

    Player player = {};
    player.p.x = 2;
    player.p.y = 4;

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        float playerHeight = 1.5f;
        float playerWidth = 0.8f;

        float pixelsPerMeter = 32.0f / playerWidth;

        Vector2 inputDir = {};

        if(IsKeyDown(KEY_W))
        {
            inputDir.y--;
        }
        if(IsKeyDown(KEY_A))
        {
            inputDir.x--;
        }
        if(IsKeyDown(KEY_S))
        {
            inputDir.y++;
        }
        if(IsKeyDown(KEY_D))
        {
            inputDir.x++;
        }

        if(LengthSq(inputDir) > 1)
        {
            inputDir *= 1 / sqrtf(LengthSq(inputDir));
        }

        float acceleration = 35.0f;
        Vector3 ddp = {};
        ddp.x = inputDir.x * acceleration;
        ddp.y = inputDir.y * acceleration;

        if(IsKeyPressed(KEY_SPACE))
        {
            ddp.z += 200.0f;
        }

        float dt = GetFrameTime();

        ddp.x -= 7.0f * player.dp.x; // Friction
        ddp.y -= 7.0f * player.dp.y; // Friction
        ddp.z -= 9.8f; // Gravity

        player.dp += ddp*dt;
        player.p += player.dp*dt;

        if(player.p.z < 0)
        {
            player.p.z = 0;
            player.dp.z = 0;
        }

        Vector3 shadowPos = player.p;
        shadowPos.z = 0;

        float pi = 3.14159f;
        float angle = 0.25f * pi;

        Vector2 playerScreenPos = ProjectPoint(player.p, angle);
        Vector2 shadowScreenPos = ProjectPoint(shadowPos, angle);

        Vector2 playerSize = Vector2 { playerWidth, playerHeight };
        Vector2 shadowSize = Vector2 { playerWidth, playerWidth };
        Rectangle playerRec = RecBottomCenterWidthHeight(playerScreenPos * pixelsPerMeter, playerSize * pixelsPerMeter);
        Rectangle shadowRec = RecBottomCenterWidthHeight(shadowScreenPos * pixelsPerMeter, shadowSize * pixelsPerMeter);

        DrawText("Hello, World!", 50, 100, 50, MAROON);

        DrawRectangleRec(shadowRec, ColorAlpha(BLACK, 0.5f));
        DrawRectangleRec(playerRec, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

