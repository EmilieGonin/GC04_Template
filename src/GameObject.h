#pragma once

#include <vector>
#include <memory>
#include "Component/AComponent.h"
#include <SFML/Graphics/Sprite.hpp>

class GameObject 
{

public:
    GameObject();
    ~GameObject();
    void AddComponent(std::shared_ptr<AComponent> component);
    void RemoveComponent(std::shared_ptr<AComponent> component);
    void Update();
    void SetSize(const sf::Vector2f& ratioWindow);

    template<typename T>
    std::shared_ptr<T> GetComponent();

    template<typename T>
    std::vector<std::shared_ptr<T>> GetAllComponents();

private:
    void Start();
    std::vector<std::shared_ptr<AComponent>> m_components;
    bool m_isStarted;

};

template<typename T>
inline std::shared_ptr<T> GameObject::GetComponent()
{
    for (auto component : m_components)
    {
        auto componentCasted = std::dynamic_pointer_cast<T>(component);
        if (componentCasted)
        {
            return componentCasted;
        }
    }
    return nullptr;
}

template<typename T>
inline std::vector<std::shared_ptr<T>> GameObject::GetAllComponents()
{
    std::vector<std::shared_ptr<T>> result{};

    for (auto component : m_components)
    {
        auto componentCasted = std::dynamic_pointer_cast<T>(component);
        if (componentCasted)
        {
            result.push_back(componentCasted);
        }
    }
    return result;
}
