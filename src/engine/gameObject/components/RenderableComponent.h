//
// Created by david on 7/8/26.
//

#ifndef GAME_RENDERABLECOMPONENT_H
#define GAME_RENDERABLECOMPONENT_H

#include "engine/gameObject/Component.h"


class Renderer;

class TransformComponent;

class RenderableComponent : public Component
{
public:
     RenderableComponent();
     void draw(Renderer& renderer);
};


#endif //GAME_RENDERABLECOMPONENT_H
