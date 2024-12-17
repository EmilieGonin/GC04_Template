#include "Scene.h"



Scene::Scene() : _gos()
{
}

void Scene::Update()
{
	for (auto gameObject : _gos)
	{
		gameObject->Update();
	}
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}
