//
// Created by david on 2026-07-06.
//

#ifndef GAME_TRANSFORM_H
#define GAME_TRANSFORM_H

#include "../Component.h"

class Transform : public Component
{
public :
    float x = 0, y = 0, z = 0;
};


#endif //GAME_TRANSFORM_H