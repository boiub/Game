//
// Created by david on 2026-07-06.
//

#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H
#include <memory>
#include <vector>

#include "Component.h"


class GameObject
{
public:
    template<typename T, typename... Args> T &addComponent(Args &&... args)
    {
        auto component = std::make_unique<T>(std::forward<Args>(args)...);
        component->gameObject = this;

        T& ref = *component;
        components.push_back(std::move(component));

        return ref;
    }

    template<typename T> T *getComponent()
    {
        for (auto &component : components)
        {
            if (auto ptr = dynamic_cast<T*>(component.get()))
                return ptr;
        }

        return nullptr;
    }

private:
    std::vector<std::unique_ptr<Component>> components;
};


#endif //GAME_GAMEOBJECT_H