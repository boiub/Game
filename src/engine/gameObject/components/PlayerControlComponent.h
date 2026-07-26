//
// Created by david on 2026-07-17.
//

#ifndef GAME_PLAYERCONTROLCOMPONENT_H
#define GAME_PLAYERCONTROLCOMPONENT_H
#include "engine/gameObject/Component.h"


class PlayerControlComponent : public TypedComponent<PlayerControlComponent>
{
public:
    explicit PlayerControlComponent() = default;

    void update(float dt) override;
};


#endif //GAME_PLAYERCONTROLCOMPONENT_H