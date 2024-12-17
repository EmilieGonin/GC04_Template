#include "GameObject.h"

void GameObject::addComponent(const std::shared_ptr<AComponent>& component)
{
	components.push_back(component);
}

void GameObject::update()
{
	for (auto component : components)
	{
		component->update();
	}
}
