//
// Created by david on 2026-07-07.
//



#include "Renderer.h"

void Renderer::initializeRenderer(int renX, int renY)
{
    InitWindow(renX, renY, "FUCKYEAH");
    SetTargetFPS(60);
}

void Renderer::render()
{
    BeginDrawing();

    EndDrawing();
}