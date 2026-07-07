//
// Created by david on 2026-07-06.
//

#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include <memory>
#include <stdexcept>
#include <unordered_map>
#include <vector>

#include "Component.h"

class GameObject
{
public:

    template<typename T, typename... Args>
    T& addComponent(Args&&... args)
    {
        // Prevent duplicate components
        if (getComponent<T>() != nullptr)
            throw std::runtime_error("Component already exists on GameObject.");

        auto component = std::make_unique<T>(std::forward<Args>(args)...);
        component->gameObject = this;

        T& ref = *component;

        componentLookup[Component::getTypeID<T>()] = component.get();
        components.push_back(std::move(component));

        return ref;
    }

    template<typename T>
    T* getComponent()
    {
        auto it = componentLookup.find(Component::getTypeID<T>());

        if (it == componentLookup.end())
            return nullptr;

        return static_cast<T*>(it->second);
    }

    void update(float dt);

private:
    std::vector<std::unique_ptr<Component>> components;
    std::unordered_map<size_t, Component*> componentLookup;
};

#endif //GAME_GAMEOBJECT_H