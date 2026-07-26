//
// Created by david on 2026-07-07.
//


#include "Scene.h"

#include "engine/gameObject/components/PlayerTagComponent.h"

void Scene::loadScene(const SceneID id)
{
    if (!SceneIDToString(id)) LOG_WARNING("Unknown SceneID was used when loading. May be missing from SceneIDToString(SceneID id) function");
    else LOG_INFO(std::string("Loading scene: ") + SceneIDToString(id));
    gameObjects.clear();

    auto [gameObjects] = sceneMap.at(id)(assets);

    for (auto& d : gameObjects)
    {
        GameObject& obj = createGameObject();
        obj.scene = this;
        for (auto& c : d.components)
            obj.addComponent(std::move(c));

        for (auto& c : obj.components)
        {
            c->init();
        }
    }

    LOG_INFO("Scene loaded successfully. Created " + std::to_string(gameObjects.size()) + " game objects.");
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

void Scene::insertPlayer(std::unique_ptr<GameObject> player)
{
    player->scene = this;
    gameObjects.push_back(std::move(player));
    LOG_INFO("Player inserted into scene.");
}

std::unique_ptr<GameObject> Scene::extractPlayer()
{
    for (auto object = gameObjects.begin(); object != gameObjects.end(); ++object)
    {
        if ((*object)->getComponent<PlayerTagComponent>())
        {
            auto player = std::move(*object);
            gameObjects.erase(object);
            player->scene = nullptr;

            LOG_INFO("Player extracted from scene.");
            return player;
        }
    }

    LOG_ERROR("No player was found in Scene::gameobjects for extraction");
    return nullptr;
}
