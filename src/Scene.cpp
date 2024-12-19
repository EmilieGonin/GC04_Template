#pragma once

#include "Scene.h"
#include "AssetManager.h"
#include "GameObject.h"
#include "./Component/Behaviour/BackgroundBehaviour.h"
#include "./Component/Behaviour/BrickBehaviour.h"
#include "./Component/Transform/TransformSFML.h"
#include "./Component/Draw/DrawableSFML.h"
#include "./Component/Draw/SpriteRenderer.h"
#include "Component/Collider/CircleCollider.h"


Scene::Scene() : 
	_gos()
{

}

void Scene::InstanciateBackground(const sf::Vector2f& windowSize)
{
	std::shared_ptr<GameObject> background = std::shared_ptr<GameObject>(new GameObject());
	std::shared_ptr<BackgroundBehaviour> backgroundBehaviour = std::shared_ptr<BackgroundBehaviour>(new BackgroundBehaviour());
	background->AddComponent(backgroundBehaviour);


	backgroundBehaviour->Init(windowSize);

	std::shared_ptr<GameObject> testCollider = std::make_shared<GameObject>();
	std::shared_ptr<TransformSFML> transform = std::make_shared<TransformSFML>();
	std::shared_ptr<CircleCollider> collider = std::make_shared<CircleCollider>();
	collider->m_radius = 50.f;

	testCollider->AddComponent(transform);
	testCollider->AddComponent(collider);

	_gos.push_back(background);
	_gos.push_back(testCollider);
}

void Scene::InstanciateBrick()
{
	std::shared_ptr<GameObject> background = std::shared_ptr<GameObject>(new GameObject());
	std::shared_ptr<BrickBehaviour> brickBehaviour = std::shared_ptr<BrickBehaviour>(new BrickBehaviour());
	background->AddComponent(brickBehaviour);

	brickBehaviour->Init();
	_gos.push_back(background);
}

void Scene::InstanciateLineBricks(const int count, const int maxWidth, const int posY)
{
	std::shared_ptr<sf::Texture> textureRef = AssetManager::GetInstance().GetTexture(TextureType::BRICK);

	int sizeX = textureRef->getSize().x; 
	int totalBlockWidth = count * sizeX;
	float remainingSpace = maxWidth - totalBlockWidth;
	float offset = remainingSpace / (count + 1);

	for (size_t i = 0; i < count; i++)
	{
		InstanciateBrick(); 
		std::shared_ptr<ATransform> transform = _gos[_gos.size() - 1]->GetComponent<ATransform>();
		
		float newX = offset + i * (sizeX + offset);
		transform->SetPosition(newX, posY);
	}
}

void Scene::InstanciateColonBricks(const int countColon, const int countLine, const int maxWidth)
{
	std::shared_ptr<sf::Texture> textureRef = AssetManager::GetInstance().GetTexture(TextureType::BRICK);

	int sizeY = textureRef->getSize().y;

	for (size_t i = 0; i < countColon; i++)
	{
		float newY = (sizeY * (i * 2));
		if (i % 2 == 0) 
		{
			InstanciateLineBricks(countLine + 1, maxWidth, newY);
		}
		else 
		{
			InstanciateLineBricks(countLine, maxWidth, newY);
		}
		//InstanciateLineBricks(countLine, maxWidth, newY);
	}
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
