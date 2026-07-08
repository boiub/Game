//
// Created by david on 2026-07-07.
//



#include "Renderer.h"
#include "engine/gameObject/components/RenderableComponent.h"

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

void Renderer::requestRenderable(RenderableComponent& renderableComponent)
{

}