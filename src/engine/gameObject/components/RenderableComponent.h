//
// Created by david on 7/8/26.
//

#ifndef GAME_RENDERABLECOMPONENT_H
#define GAME_RENDERABLECOMPONENT_H

#include "raylib.h"

#include "engine/gameObject/Component.h"
#include "engine/main/scene/AssetManager.h"


class Renderer;

class TransformComponent;

class RenderableComponent : public Component
{
public:
    RenderableComponent();
    void draw(Renderer& renderer);

    void setAssetType(AssetType type) { assetType = type; }
    void setTexture(Texture2D &t) { texture = &t; }
private:
    AssetType assetType;
    Texture2D* texture;
};


#endif //GAME_RENDERABLECOMPONENT_H
