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


    /*
     * loadScene() kräver att vi har ett sätt att ladda in en scen på något sätt.
     * Här ska alla GameObjects laddas in enligt filen och få sina komponenter.
     * Viktigt att renderableComponent får en pointer till sin texture här.
     */
    void loadScene();
private:
    GameObject& createGameObject();

    std::vector<std::unique_ptr<GameObject>> gameObjects;
};


#endif //GAME_SCENE_H