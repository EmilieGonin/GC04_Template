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
#include "Component/Collider/RectCollider.h"
#include "Component/Behaviour/SliderBehaviour.h"
#include "Component/Behaviour/BallBehaviour.h"
#include "Component/ColliderSystem.h"


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
	_gos.push_back(background);


	std::shared_ptr<GameObject> slider = std::shared_ptr<GameObject>(new GameObject());
	std::shared_ptr<SliderBehaviour> sliderBehaviour = std::shared_ptr<SliderBehaviour>(new SliderBehaviour());
	slider->AddComponent(sliderBehaviour);
	_gos.push_back(slider);

	std::shared_ptr<GameObject> ball = std::shared_ptr<GameObject>(new GameObject());
	std::shared_ptr<BallBehaviour> ballBehaviour = std::shared_ptr<BallBehaviour>(new BallBehaviour());
	ball->AddComponent(ballBehaviour);
	_gos.push_back(ball);

	std::shared_ptr<GameObject> colliderLeft = std::shared_ptr<GameObject>(new GameObject());
	std::shared_ptr<GameObject> colliderRight = std::shared_ptr<GameObject>(new GameObject());
	std::shared_ptr<GameObject> colliderTop = std::shared_ptr<GameObject>(new GameObject());
	std::shared_ptr<GameObject> colliderBot = std::shared_ptr<GameObject>(new GameObject());

	std::shared_ptr<RectCollider> rectColliderLeft = std::shared_ptr<RectCollider>(new RectCollider());
	std::shared_ptr<RectCollider> rectColliderRight = std::shared_ptr<RectCollider>(new RectCollider());
	std::shared_ptr<RectCollider> rectColliderTop = std::shared_ptr<RectCollider>(new RectCollider());
	std::shared_ptr<RectCollider> rectColliderBot = std::shared_ptr<RectCollider>(new RectCollider());

	rectColliderLeft->SetRectBounds(sf::FloatRect(sf::Vector2f(0.f,0.f),sf::Vector2f(5.f, 900.f )));
	rectColliderRight->SetRectBounds(sf::FloatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(-5.f, 900.f)));
	rectColliderTop->SetRectBounds(sf::FloatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(1600.f, 5.f)));
	rectColliderBot->SetRectBounds(sf::FloatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(1600.f, -5.f)));

	colliderLeft->AddComponent(rectColliderLeft);
	colliderRight->AddComponent(rectColliderRight);
	colliderTop->AddComponent(rectColliderTop);
	colliderBot->AddComponent(rectColliderBot);

	colliderLeft->GetComponent<TransformSFML>()->setPosition(sf::Vector2f(-2.f, 0.f));
	colliderRight->GetComponent<TransformSFML>()->setPosition(sf::Vector2f(1602.f, 0.f));
	colliderTop->GetComponent<TransformSFML>()->setPosition(sf::Vector2f(0.f, -2.f));
	colliderBot->GetComponent<TransformSFML>()->setPosition(sf::Vector2f(0.f, 902.f));

	_gos.push_back(colliderLeft);
	_gos.push_back(colliderRight);
	_gos.push_back(colliderTop);
	_gos.push_back(colliderBot);

	

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
	ColliderSystem::GetInstance().CheckCollisions();
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
		auto drawables = gameObject->GetAllComponents<DrawableSFML>();
		for (auto drawable : drawables)
		{
			target.draw(*drawable);

		}
	}
}
