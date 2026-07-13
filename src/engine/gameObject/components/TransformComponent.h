//
// Created by david on 2026-07-06.
//

#ifndef GAME_TRANSFORM_H
#define GAME_TRANSFORM_H

#include "raylib.h"

#include "../Component.h"


class TransformComponent : public TypedComponent<TransformComponent>
{
public :
    TransformComponent(Vector3 p, Vector3 r, Vector3 s) : position(p), rotation(r), scale(s) {};

    Vector3 position{0.f, 0.f, 0.f};
    Vector3 rotation{0.f, 0.f, 0.f};
    Vector3 scale{0.f, 0.f, 0.f};
};


#endif //GAME_TRANSFORM_H