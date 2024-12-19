#pragma once

#include "GameObject.h"
#include "./Component/Transform/ATransform.h"
#include "./Component/Transform/TransformSFML.h"

GameObject::GameObject()
{
    std::shared_ptr<ATransform> transform = std::shared_ptr<ATransform>(new TransformSFML());
    AddComponent(transform);
}

GameObject::~GameObject()
{
}

void GameObject::AddComponent(std::shared_ptr<AComponent> component)
{    
    for (auto existingComponent : m_components)
    {
        if (typeid(*existingComponent) == typeid(*component))
        {
            return;
        }
    }

    component->Init(std::shared_ptr<GameObject>(this));
	m_components.push_back(component);
    if (m_isStarted)
    {
        component->Start();
    }
}

void GameObject::RemoveComponent(std::shared_ptr<AComponent> component)
{
    m_components.erase(std::remove(
        m_components.begin(), 
        m_components.end(), 
        component), m_components.end());
}

void GameObject::Update()
{
    if (!m_isStarted)
    {
        Start();
    }
	for (auto component : m_components)
	{
		component->Update();
	}
}

void GameObject::SetSize(const sf::Vector2f& ratioWindow)
{
    std::shared_ptr<ATransform> transform = GetComponent<ATransform>();

    if (transform) 
    {
        transform->SetScale(ratioWindow.x, ratioWindow.y);
    }
}

void GameObject::Start()
{
    m_isStarted = true;
    for (auto component : m_components)
    {
        component->Start();
    }
}
