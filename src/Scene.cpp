#include "Scene.h"



void Scene::Update()
{
	for (auto gameObject : _gos)
	{
		gameObject->update();
	}
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}
