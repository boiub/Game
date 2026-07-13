//
// Created by david on 2026-07-07.
//

#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <memory>
#include <vector>

#include "engine/gameObject/GameObject.h"
#include "scenes/Scenes.h"

enum class SceneID
{
    Test,
};

using SceneFactory = SceneData (*)(AssetManager&);

inline std::unordered_map<SceneID, SceneFactory> sceneMap =
{
    { SceneID::Test, createTestScene }
};

class Scene {
public:
    Scene() = default;

    void update(float dt) const;
    void draw(Renderer& renderer) const;

    void loadScene(SceneID id);
private:
    GameObject& createGameObject();

    std::vector<std::unique_ptr<GameObject>> gameObjects;

    AssetManager assets;
};


#endif //GAME_SCENE_H