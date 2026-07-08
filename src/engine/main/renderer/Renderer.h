//
// Created by david on 2026-07-07.
//

#ifndef GAME_RENDERER_H
#define GAME_RENDERER_H

#include <cmath>

#include "raylib.h"
#include "engine/gameObject/components/RenderableComponent.h"

class Renderer
{
public:
    void initializeRenderer(int resX, int resY);
    void render();

    void requestRenderable(RenderableComponent& renderableComponent);

private:
    Vector2 ProjectPoint(Vector3 p, float angle) { return {p.x, cosf(angle) * p.y - sinf(angle) * p.z}; }
};


#endif //GAME_RENDERER_H