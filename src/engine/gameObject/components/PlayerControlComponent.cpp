//
// Created by david on 2026-07-17.
//

#include "PlayerControlComponent.h"

#include <algorithm>
#include <cmath>

#include "raylib.h"
#include "TransformComponent.h"
#include "engine/gameObject/GameObject.h"

void PlayerControlComponent::update(float dt)
{
    constexpr float FORCE = 8.f;

    if (IsKeyDown(KEY_W)) velocity.y -= FORCE;
    if (IsKeyDown(KEY_S)) velocity.y += FORCE;
    if (IsKeyDown(KEY_A)) velocity.x -= FORCE;
    if (IsKeyDown(KEY_D)) {velocity.x += FORCE; printf("whw");}



    if (IsKeyUp(KEY_W) && IsKeyUp(KEY_S))
    {
        if (velocity.y > 0)
            velocity.y = std::max(0.0f, velocity.y - FORCE * 1.5f);
        else
            velocity.y = std::min(0.0f, velocity.y + FORCE * 1.5f);
    }

    if (IsKeyUp(KEY_A) && IsKeyUp(KEY_D))
    {
        if (velocity.x > 0)
            velocity.x = std::max(0.0f, velocity.x - FORCE * 1.5f);
        else
            velocity.x = std::min(0.0f, velocity.x + FORCE * 1.5f);
    }

    velocity = clampedVelocity(velocity);

    gameObject->getComponent<TransformComponent>()->position += velocity * dt;
}
