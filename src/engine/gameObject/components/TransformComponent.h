//
// Created by david on 2026-07-06.
//

#ifndef GAME_TRANSFORM_H
#define GAME_TRANSFORM_H

#include "raylib.h"

#include "../Component.h"


class TransformComponent : public Component
{
public :
    Vector3 position{0.f, 0.f, 0.f};
    Vector3 rotation{0.f, 0.f, 0.f};
    Vector3 scale{0.f, 0.f, 0.f};
};


#endif //GAME_TRANSFORM_H