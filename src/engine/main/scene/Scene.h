//
// Created by david on 2026-07-07.
//

#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <memory>
#include <vector>

#include "engine/gameObject/GameObject.h"

class Scene {
public:
    Scene();

    void update(float dt);
    void draw();

    GameObject&  createGameObject();
private:
    std::vector<std::unique_ptr<GameObject>> gameObjects;
};


#endif //GAME_SCENE_H