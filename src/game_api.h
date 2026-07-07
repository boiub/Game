#ifndef GAME_API_H
#define GAME_API_H

struct Player
{
    Vector3 p;
    Vector3 dp;
};

struct GameState
{
    Player player;
};

extern "C"
{
    void GameInit(GameState *state);
    void GameUpdate(GameState *state);
}

#endif
