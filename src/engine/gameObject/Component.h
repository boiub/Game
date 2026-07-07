//
// Created by david on 2026-07-06.
//

#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

class GameObject;

class Component
{
public:
    virtual ~Component() = default;

    GameObject* gameObject = nullptr;
};


#endif //GAME_COMPONENT_H