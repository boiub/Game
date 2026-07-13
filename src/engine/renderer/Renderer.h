//
// Created by david on 2026-07-07.
//

#ifndef GAME_RENDERER_H
#define GAME_RENDERER_H

#include <array>
#include <cmath>
#include <unordered_map>
#include <vector>

#include "raylib.h"

#include "engine/gameObject/components/RenderableComponent.h"


/*
 * LayerID is used to identify the order in which a renderable components texture will be drawn with enums with lower
 * value will be drawn first, aka lowest priority. Components with the same LayerID will be drawn in an arbitrary order
 * based on which object sent the request first.
 */
enum class LayerID
{
    Debug1 = 100
};

constexpr std::array LayerIDs =
{
    LayerID::Debug1
};

const int VIEW_ANGLE = 45;

class Renderer
{
public:
    void initializeRenderer(int resX, int resY);
    void render();

    void requestRenderable(RenderableComponent& renderableComponent, LayerID layerID);

private:
    static Vector2 ProjectPoint(Vector3 p, float angle) { return {p.x, cosf(angle) * p.y - sinf(angle) * p.z}; }
    std::unordered_map<LayerID, std::vector<std::pair<Texture2D*, Vector2>>> renderMap;
};


#endif //GAME_RENDERER_H