//
// Created by david on 2026-07-06.
//

#include "GameObject.h"

void GameObject::update(float dt)
{
    for (auto& component : components)
    {
        component->update(dt);
    }
}
