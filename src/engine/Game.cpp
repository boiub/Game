//
// Created by david on 2026-07-07.
//

#include "raylib.h"

#include "Game.h"

#include "gameObject/components/PhysicsComponent.h"
#include "gameObject/components/PlayerControlComponent.h"
#include "gameObject/components/PlayerTagComponent.h"


void Game::run()
{
    init();
    loop();
}


void Game::init()
{
    LOG_INFO("Initializing Game");
    renderer.initializeRenderer(1080, 720);
    scene.loadScene(SceneID::Test);
    initPlayer();
}

void Game::loop()
{
    LOG_INFO("Starting game loop");
    while (running && !WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        update(deltaTime);

        draw();

    }

    LOG_INFO("Ending game loop");

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

void Game::initPlayer()
{
    LOG_INFO("Initializing Player");
    auto player = std::make_unique<GameObject>();

    player->addComponent<TransformComponent>(
    Vector3{0.f, 0.f, 0.f},
    Vector3{0.f, 0.f, 0.f},
    Vector3{1.f, 1.f, 1.f});

    Texture2D t = LoadTexture("../assets/test.png");
    if (!IsTextureValid(t)) LOG_ERROR("Failed to load player texture");

    player->addComponent<RenderableComponent>(t);
    player->addComponent<PlayerControlComponent>();
    player->addComponent<PlayerTagComponent>();
    player->addComponent<PhysicsComponent>();
}
