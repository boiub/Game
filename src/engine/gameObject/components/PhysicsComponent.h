#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include <algorithm>

#include "raylib.h"
#include "raymath.h"

#include "engine/gameObject/Component.h"
#include "game_math.h"

struct AABB
{
    Vector3 center;
    Vector3 halfSize;

    inline Vector3 MinCorner() const { return center - halfSize; }
    inline Vector3 MaxCorner() const { return center + halfSize; }

    AABB MinkowskiDifference(const AABB& other) const
    {
        return AABB {
            this->center - other.center,
            this->halfSize + other.halfSize
        };
    }

    static AABB FromMinMax(const Vector3& min, const Vector3& max)
    {
        AABB bounds;
        bounds.center = (min + max) * 0.5f;
        bounds.halfSize = (max - min) * 0.5f;
        return bounds;
    }

    AABB CombinedBounds(const AABB& other) const
    {
        Vector3 min = Min(this->MinCorner(), other.MinCorner());
        Vector3 max = Max(this->MaxCorner(), other.MaxCorner());
        return FromMinMax(min, max);
    }
};

class PhysicsComponent : public TypedComponent<PhysicsComponent>
{
public:
    float frictionCoefficient = 0;

    // TODO(Michael): Support rounded shapes (maybe everything is a rounded rectangle), otherwise we'll get stuck on corners. Alternatively we could do a search in P instead of T which could achieve a similar effect.
    Vector3 offset; // Offset from transform position center
    Vector3 halfSize;

    PhysicsComponent();

    AABB GetBoundsAt(Vector3 position);
    AABB GetBounds();
    void update(float dt) override;
    void addForce(Vector3 f);
private:
    Vector3 accelerationForFrame;
    Vector3 velocity;

    void doPhysicsStep(float dt, Vector3 acceleration);
};

#endif
