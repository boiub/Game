//
// Created by david on 2026-07-06.
//

#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include <cstddef>

class GameObject;

class Component
{
    friend class GameObject;

public:
    virtual ~Component() = default;

    virtual void update(float dt) {}

    [[nodiscard]] virtual size_t getRuntimeTypeID() const = 0;

    template<typename T>
    static size_t getTypeID()
    {
        static const size_t typeID = nextTypeID++;
        return typeID;
    }

    GameObject* getGameObject()
    {
        return gameObject;
    }

protected:
    GameObject* gameObject = nullptr;

private:
    inline static size_t nextTypeID = 0;
};

template<typename T>
class TypedComponent : public Component
{
public:
    size_t getRuntimeTypeID() const override
    {
        return Component::getTypeID<T>();
    }
};

#endif //GAME_COMPONENT_H