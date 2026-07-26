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
#include "Logger.h"

class Scene;

class GameObject
{
public:

    template<typename T, typename... Args> T& addComponent(Args&&... args)
    {
        if (getComponent<T>())
            throw std::runtime_error("Component already exists on GameObject.");

        auto component = std::make_unique<T>(std::forward<Args>(args)...);

        component->gameObject = this;

        T& ref = *component;

        componentLookup[component->getRuntimeTypeID()] = component.get();

        components.push_back(std::move(component));

        return ref;
    }

    Component& addComponent(std::unique_ptr<Component> component)
    {
        if (componentLookup.find(component->getRuntimeTypeID()) != componentLookup.end())
            throw std::runtime_error("Component already exists on GameObject.");

        component->gameObject = this;

        Component& ref = *component;

        componentLookup[component->getRuntimeTypeID()] = component.get();

        components.push_back(std::move(component));

        return ref;
    }

    template<typename T> T* getComponent()
    {
        auto it = componentLookup.find(Component::getTypeID<T>());

        if (it == componentLookup.end())
            return nullptr;

        return static_cast<T*>(it->second);
    }

    template<typename T> void requireComponent()
    {
        static_assert(std::is_base_of_v<Component, T>, "T must derive from Component");

        if (!getComponent<T>()) LOG_FATAL("Required component does not exist");
    }

    void update(float dt);

    Scene* scene;
    std::vector<std::unique_ptr<Component>> components;
private:

    std::unordered_map<size_t, Component*> componentLookup;
};

#endif //GAME_GAMEOBJECT_H