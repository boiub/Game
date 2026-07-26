//
// Created by david on 2026-07-17.
//

#include "PlayerControlComponent.h"

#include "raylib.h"
#include "engine/gameObject/GameObject.h"
#include "engine/gameObject/components/PhysicsComponent.h"

void PlayerControlComponent::update(float dt)
{
    constexpr float FORCE = 8.f;

    auto pc = gameObject->getComponent<PhysicsComponent>();

    if (IsKeyDown(KEY_W)) pc->addForce({0.f, -FORCE, 0.f});
    if (IsKeyDown(KEY_S)) pc->addForce({0.f, FORCE, 0.f});
    if (IsKeyDown(KEY_A)) pc->addForce({-FORCE, 0.f, 0.f});
    if (IsKeyDown(KEY_D)) pc->addForce({FORCE, 0.f, 0.f});

}
