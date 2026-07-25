//
// Created by david on 2026-07-17.
//

#ifndef GAME_PLAYERCONTROLCOMPONENT_H
#define GAME_PLAYERCONTROLCOMPONENT_H
#include "raylib.h"
#include "raymath.h"
#include "engine/gameObject/Component.h"


class PlayerControlComponent : public TypedComponent<PlayerControlComponent>
{
public:
    explicit PlayerControlComponent() = default;

    void update(float dt) override;

private:
    static Vector3 clampedVelocity(const Vector3 velocity)
    {
        constexpr float MAX_VELOCITY = 300.0f;
        Vector2 xy = {velocity.x, velocity.y};

        if (Vector2Length(xy) > MAX_VELOCITY)
        {
            xy *= MAX_VELOCITY/Vector2Length(xy);
        }

        return {xy.x, xy.y, velocity.z};
    }

    Vector3 velocity = {0.f, 0.f, 0.f};
};


#endif //GAME_PLAYERCONTROLCOMPONENT_H