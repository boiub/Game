//
// Created by david on 2026-07-07.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "renderer/Renderer.h"
#include "scene/Scene.h"

class Game {
public:
    Game() = default;

    void run();

private:
    void init();
    void loop();

    void update(float dt);
    void draw();

    bool running = true;

    Scene scene;
    Renderer renderer;
};


#endif //GAME_GAME_H