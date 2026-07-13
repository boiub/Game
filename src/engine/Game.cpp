//
// Created by david on 2026-07-07.
//

#include "raylib.h"

#include "Game.h"


void Game::run()
{
    init();
    loop();
}


void Game::init()
{
    renderer.initializeRenderer(1080, 720);
    scene.loadScene(SceneID::Test);
}

void Game::loop()
{
    while (running && !WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        update(deltaTime);

        draw();

    }

    CloseWindow();
}

void Game::update(float deltaTime)
{
    scene.update(deltaTime);
}

void Game::draw()
{
    scene.draw(renderer);
    renderer.render();
}