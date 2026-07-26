//
// Created by david on 2026-07-26.
//

#ifndef GAME_PLAYERTAGCOMPONENT_H
#define GAME_PLAYERTAGCOMPONENT_H
#include "engine/gameObject/Component.h"

class PlayerTagComponent : public TypedComponent<PlayerTagComponent>
{
public:
    PlayerTagComponent() { LOG_INFO("Loaded PlayerTagComponent"); }
};


#endif //GAME_PLAYERTAGCOMPONENT_H