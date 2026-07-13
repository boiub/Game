//
// Created by david on 7/8/26.
//

#ifndef GAME_RENDERABLECOMPONENT_H
#define GAME_RENDERABLECOMPONENT_H

#include "raylib.h"

#include "engine/gameObject/Component.h"


class Renderer;

class RenderableComponent : public TypedComponent<RenderableComponent>
{
public:
    explicit RenderableComponent(Texture2D &t);
    void draw(Renderer& renderer);

    void setTexture(Texture2D &t) { texture = &t; }
    Texture2D* getTexture() const { return texture; }

private:
    Texture2D* texture;
};


#endif //GAME_RENDERABLECOMPONENT_H
