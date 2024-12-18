#pragma once

#include "Scene.h"
#include "AssetManager.h"
#include "GameObject.h"
#include "./Component/Behaviour/BackgroundBehaviour.h"
#include "./Component/Transform/TransformSFML.h"
#include "./Component/Draw/DrawableSFML.h"
#include "./Component/Draw/SpriteRenderer.h"


Scene::Scene() : 
	_gos()
{

}

void Scene::InitBackground(const sf::Vector2f& windowSize)
{
	std::shared_ptr<GameObject> background = std::shared_ptr<GameObject>(new GameObject());

	std::shared_ptr<BackgroundBehaviour> backgroundBehaviour = std::shared_ptr<BackgroundBehaviour>(new BackgroundBehaviour());
	std::shared_ptr<SpriteRenderer> spriteRenderer = std::shared_ptr<SpriteRenderer>(new SpriteRenderer());
	
	background->AddComponent(spriteRenderer);
	background->AddComponent(backgroundBehaviour);

	backgroundBehaviour->Init(windowSize);
	_gos.push_back(background);
}

void Scene::Update()
{
	for (auto gameObject : _gos)
	{
		gameObject->Update();
	}
}

void Scene::SetSize(const sf::Vector2f& ratioWindow)
{
	for (auto gameObject : _gos)
	{
		gameObject->SetSize(ratioWindow);
	}
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto gameObject : _gos)
	{
		std::shared_ptr<TransformSFML> transform = gameObject->GetComponent<TransformSFML>();
		std::shared_ptr<DrawableSFML> drawable = gameObject->GetComponent<DrawableSFML>();

		if(drawable)
		{
			target.draw(*drawable, transform->getTransform());
		}
	}
}
