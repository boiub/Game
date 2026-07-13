//
// Created by david on 7/8/26.
//

#include "RenderableComponent.h"

#include <cassert>

#include "engine/gameObject/GameObject.h"
#include "engine/renderer/Renderer.h"
#include "TransformComponent.h"

#include "engine/renderer/Renderer.h"

RenderableComponent::RenderableComponent(Texture2D &t)
{
    // Make sure the object has a TransformComponent before adding this Renderable
    texture = &t;
}

void RenderableComponent::draw(Renderer& renderer)
{
    renderer.requestRenderable(*this, LayerID::Debug1);
}

