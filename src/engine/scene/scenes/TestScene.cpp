//
// Created by david on 2026-07-09.
//

#include <memory>
#include <vector>

#include "Scenes.h"
#include "engine/gameObject/components/PhysicsComponent.h"
#include "engine/gameObject/components/PlayerControlComponent.h"
#include "engine/scene/Scene.h"

void createObject1(AssetManager& assets, SceneData& scene);


SceneData createTestScene(AssetManager& assets)
{
    LOG_INFO("Creating test scene");

    SceneData scene;

    createObject1(assets, scene);


    return scene;
}


void createObject1(AssetManager& assets, SceneData& scene)
{
    GameObjectData object;

    object.components.push_back(
        std::make_unique<TransformComponent>(
            Vector3{20, 20, 0},
            Vector3{0, 0, 0},
            Vector3{1, 1, 1}
            )
        );

    object.components.push_back(
        std::make_unique<RenderableComponent>(
            *assets.loadAsset(AssetType::Test1)
            )
        );

    object.components.push_back(
        std::make_unique<PlayerControlComponent>()
        );

    object.components.push_back(
        std::make_unique<PhysicsComponent>()
        );

    scene.gameObjects.push_back(std::move(object));
}