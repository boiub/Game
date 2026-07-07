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

    template<typename T> static size_t getTypeID()
    {
        static const size_t typeID = nextTypeID++;
        return typeID;
    }

protected:
    GameObject* gameObject = nullptr;

private:
    inline static size_t nextTypeID = 0;
};

#endif //GAME_COMPONENT_H