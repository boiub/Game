//
// Created by david on 2026-07-07.
//


#include "Scene.h"

void Scene::loadScene(SceneID id)
{
    gameObjects.clear();

    auto [gameObjects] = sceneMap.at(id)(assets);

    for (auto& d : gameObjects)
    {
        GameObject& obj = createGameObject();
        for (auto& c : d.components)
            obj.addComponent(std::move(c));
    }
}

void Scene::update(float dt) const
{
    for (auto &object : gameObjects)
    {
        object->update(dt);
    }
}

void Scene::draw(Renderer& renderer) const
{
    for (auto &object : gameObjects)
    {
        if (auto r = object->getComponent<RenderableComponent>())
        {
            r->draw(renderer);
        }
    }
}

GameObject& Scene::createGameObject()
{
    auto object = std::make_unique<GameObject>();
    GameObject& ref = *object;
    gameObjects.push_back(std::move(object));

    return ref; // Vad betyder denna varning för oss? Ta bort denna kommentar om ingen varning finns
}
