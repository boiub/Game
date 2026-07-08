//
// Created by david on 7/8/26.
//

#include "RenderableComponent.h"

#include <cassert>

#include "engine/gameObject/GameObject.h"
#include "engine/main/renderer/Renderer.h"
#include "TransformComponent.h"

RenderableComponent::RenderableComponent()
{
    // Make sure the object has a TransformComponent before adding this Renderable
    assert(gameObject->getComponent<TransformComponent>() != nullptr);
}

void RenderableComponent::draw(Renderer& renderer)
{
    renderer.requestRenderable(*this);
}

