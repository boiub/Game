//
// Created by david on 2026-07-07.
//



#include "Renderer.h"

#include "engine/gameObject/GameObject.h"
#include "engine/gameObject/components/RenderableComponent.h"
#include "engine/gameObject/components/TransformComponent.h"

void Renderer::initializeRenderer(int renX, int renY)
{
    InitWindow(renX, renY, "FUCKYEAH");
    SetTargetFPS(60);
}

void Renderer::render()
{
    BeginDrawing();
    ClearBackground(BLACK);

    for (LayerID id : LayerIDs)
    {
        auto it = renderMap.find(id);
        if (it == renderMap.end())
            continue;

        for (const auto& request : it->second)
        {
            DrawTextureV(*request.first, request.second, WHITE);
        }
    }
    renderMap.clear();

    EndDrawing();
}

void Renderer::requestRenderable(RenderableComponent& renderableComponent, LayerID layerID)
{
    printf("hello");
    renderMap[layerID].emplace_back(
        renderableComponent.getTexture(),
        ProjectPoint(
            renderableComponent.getGameObject()->getComponent<TransformComponent>()->position,
            VIEW_ANGLE)
    );
}