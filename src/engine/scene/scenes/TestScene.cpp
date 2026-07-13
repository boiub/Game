//
// Created by david on 2026-07-09.
//

#include <memory>
#include <vector>

#include "Scenes.h"


SceneData createTestScene(AssetManager& assets)
{
    SceneData scene;

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

    scene.gameObjects.push_back(std::move(object));

    return scene;
}
