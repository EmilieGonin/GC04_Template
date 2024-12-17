#include "GameObject.h"

void GameObject::AddComponent(std::shared_ptr<AComponent> component)
{
	m_components.push_back(component);
    if (m_isStarted)
    {
        component->Start();
    }
}

void GameObject::RemoveComponent(std::shared_ptr<AComponent> component)
{
    m_components.erase(
        std::remove_if(
            m_components.begin(),
            m_components.end(),
            [&component](const std::shared_ptr<AComponent>& c) {
                return c == component; // Compare les pointeurs partag�s
            }
        ),
        m_components.end()
    );
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

void GameObject::Start()
{
    m_isStarted = true;
    for (auto component : m_components)
    {
        component->Start();
    }
}
