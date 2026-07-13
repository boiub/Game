//
// Created by david on 2026-07-09.
//

#ifndef GAME_SCENES_H
#define GAME_SCENES_H

// Några includes kan flaggas som onödiga av en IDE. Ta INTE bort dom. De används i funktionernas definitioner
#include "engine/gameObject/Component.h"
#include "engine/gameObject/components/RenderableComponent.h"
#include "engine/gameObject/components/TransformComponent.h"
#include "engine/scene/AssetManager.h"

struct GameObjectData
{
    std::vector<std::unique_ptr<Component>> components;
};

struct SceneData
{
    std::vector<GameObjectData> gameObjects;
};

SceneData createTestScene(AssetManager& assets);

#endif //GAME_SCENES_H