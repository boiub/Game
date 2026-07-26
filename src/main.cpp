
#include "main.h"

#include "Logger.h"
#include "engine/Game.h"


int main()
{
    auto logger = Logger();
    LOG_INFO("Logger Initialized");

    Game game;
    LOG_INFO("Starting game");
    game.run();

}

