//
// Created by david on 7/8/26.
//

#include "RenderableComponent.h"

#include <cassert>

#include "engine/gameObject/GameObject.h"
#include "engine/renderer/Renderer.h"
#include "Logger.h"
#include "TransformComponent.h"

#include "engine/renderer/Renderer.h"


RenderableComponent::RenderableComponent(Texture2D &t)
{
    texture = &t;
    if (texture == nullptr) LOG_ERROR("RenderableComponent loaded with nullptr texture");
    else LOG_INFO("Loaded RenderableComponent");
}

void RenderableComponent::init()
{
    gameObject->requireComponent<TransformComponent>();
}

void RenderableComponent::draw(Renderer& renderer)
{
    renderer.requestRenderable(*this, LayerID::Debug1);
}

