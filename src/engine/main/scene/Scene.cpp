//
// Created by david on 2026-07-07.
//

#include <iostream>

#include "engine/gameObject/components/TransformComponent.h"
#include "Scene.h"

Scene::Scene()
{
    GameObject& test = createGameObject();
    TransformComponent& t = test.addComponent<TransformComponent>();
}

void Scene::update(float dt)
{
    for (auto &object : gameObjects)
    {
        object->update(dt);
    }
}

GameObject& Scene::createGameObject()
{
    auto object = std::make_unique<GameObject>();
    GameObject& ref = *object;
    gameObjects.push_back(std::move(object));

    return ref; // Vad betyder denna varning för oss? Ta bort denna kommentar om ingen varning finns
}
