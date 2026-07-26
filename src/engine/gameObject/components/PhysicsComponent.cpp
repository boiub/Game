#include "PhysicsComponent.h"

#include <cassert>

#include "engine/gameObject/GameObject.h"

#include "game_math.h"

#include "TransformComponent.h"

PhysicsComponent::PhysicsComponent()
{
    assert(gameObject->getComponent<TransformComponent>());
}

AABB PhysicsComponent::GetBoundsAt(Vector3 position)
{
    AABB bounds;

    bounds.center = position + offset;
    bounds.halfSize = halfSize;

    return bounds;
}

AABB PhysicsComponent::GetBounds()
{
    AABB bounds = {};

    TransformComponent *transform = gameObject->getComponent<TransformComponent>();
    if (transform)
    {
        bounds = GetBoundsAt(transform->position);
    }

    return bounds;
}

std::vector<PhysicsComponent *> GetOverlappingObjects(AABB bounds)
{
    // TODO(Michael): Implement
    std::vector<PhysicsComponent *> placeholder;
    return placeholder;
}

void PhysicsComponent::update(float dt)
{
    accelerationForFrame -= velocity * frictionCoefficient;

    if (accelerationForFrame.x != 0 ||
        accelerationForFrame.y != 0 ||
        accelerationForFrame.z != 0)
    {
        doPhysicsStep(dt, accelerationForFrame);
    }

    accelerationForFrame = {};
}

void PhysicsComponent::addForce(Vector3 f)
{
    accelerationForFrame += f;
}

// TODO(Michael): Figure out acceleration from forces acting on the object
void PhysicsComponent::doPhysicsStep(float dt, Vector3 acceleration)
{
    velocity += acceleration * dt;
    Vector3 movement = velocity * dt;

    TransformComponent *transform = gameObject->getComponent<TransformComponent>();
    Vector3 position = {};

    assert(transform);
    if (transform)
    {
        position = transform->position;
    }

    AABB bounds = GetBoundsAt(position);
    AABB movementBounds = bounds.CombinedBounds(GetBoundsAt(position + movement));

    // TODO(Michael): We need some reliable way to query close physics objects. To begin with we could just return every object with a physics component, but ideally we store what references to objects that are in each eg. 1m x 1m x 1m cube in the world, then we can pull objects that are only in the cubes we overlap. If the world is dense we could probably have a 3D array of these cubes, otherwise if the world is more sprawling cubes are stored in a hashmap by hashing the cube's position (Spatial Hash)
    std::vector<PhysicsComponent *> candidates = GetOverlappingObjects(movementBounds);

    constexpr int MAX_ITERATIONS = 4;

    for (int i = 0; i < MAX_ITERATIONS; i++)
    {
        if (Length(movement) < EPSILON)
            break;

        float earliestTEntry = 1.0f;
        Vector3 normal = Vector3 {0.0f, 0.0f, 0.0f};
        bool collided = false;

        for (PhysicsComponent *other : candidates)
        {
            AABB expanded = bounds.MinkowskiDifference(other->GetBounds());

            Vector3 min = expanded.MinCorner();
            Vector3 max = expanded.MaxCorner();

            float tNearX, tFarX;
            float tNearY, tFarY;
            float tNearZ, tFarZ;

            // X slab
            if (fabsf(movement.x) < EPSILON)
            {
                if (min.x > 0.0f || max.x < 0.0f) continue;
                tNearX = -INFINITY;
                tFarX = INFINITY;
            }
            else
            {
                tNearX = min.x / movement.x;
                tFarX  = max.x / movement.x;
                if (tNearX > tFarX) std::swap(tNearX, tFarX);
            }

            // Y slab
            if (fabsf(movement.y) < EPSILON)
            {
                if (min.y > 0.0f || max.y < 0.0f) continue;
                tNearY = -INFINITY;
                tFarY = INFINITY;
            }
            else
            {
                tNearY = min.y / movement.y;
                tFarY  = max.y / movement.y;
                if (tNearY > tFarY) std::swap(tNearY, tFarY);
            }

            // Z slab
            if (fabsf(movement.z) < EPSILON)
            {
                if (min.z > 0.0f || max.z < 0.0f) continue;
                tNearZ = -INFINITY;
                tFarZ = INFINITY;
            }
            else
            {
                tNearZ = min.z / movement.z;
                tFarZ  = max.z / movement.z;
                if (tNearZ > tFarZ) std::swap(tNearZ, tFarZ);
            }

            float tEntry = std::max({tNearX, tNearY, tNearZ});
            float tExit = std::min({tFarX, tFarY, tFarZ});

            if (tEntry <= tExit && tExit >= 0.0f && tEntry <= 1.0f)
            {
                if (tEntry < earliestTEntry)
                {
                    earliestTEntry = tEntry;
                    collided = true;

                    if (tEntry == tNearX)
                    {
                        normal = movement.x > 0.0f ?
                            Vector3{-1.0f, 0.0f, 0.0f} : Vector3{1.0f, 0.0f, 0.0f};
                    }
                    else if (tEntry == tNearY)
                    {
                        normal = movement.y > 0.0f ?
                            Vector3{0.0f, -1.0f, 0.0f} : Vector3{0.0f, 1.0f, 0.0f};
                    }
                    else // tEntry == tNearZ
                    {
                        normal = movement.z > 0.0f ?
                            Vector3{0.0f, 0.0f, -1.0f} : Vector3{0.0f, 0.0f, 1.0f};
                    }
                }
            }
        }

        if (!collided)
        {
            position += movement;
            break;
        }

        // Prevent backward time stepping for initial overlaps
        earliestTEntry = std::max(0.0f, earliestTEntry);

        // Move to collision point
        position += movement * earliestTEntry;

        // Remove the part of movement going into the wall
        float remainingTime = 1.0f - earliestTEntry;
        movement *= remainingTime;

        float intoSurface = Dot(movement, normal);
        if (intoSurface < 0.0f)
            movement -= normal * intoSurface;

        // Small push out to avoid sticking
        position += normal * EPSILON;
    }

    transform->position = position;
    if (dt > 0.0f)
    {
        float inv = 1.0f / dt;
        velocity = movement * inv;
    }
}
