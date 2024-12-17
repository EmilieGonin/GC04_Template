#include "GameObject.h"

void GameObject::AddComponent(std::shared_ptr<AComponent> component)
{
	m_components.push_back(component);
}

void GameObject::RemoveComponent(std::shared_ptr<AComponent> component)
{
    m_components.erase(
        std::remove_if(
            m_components.begin(),
            m_components.end(),
            [&component](const std::shared_ptr<AComponent>& c) {
                return c == component; // Compare les pointeurs partagés
            }
        ),
        m_components.end()
    );
}

void GameObject::Update()
{

}
