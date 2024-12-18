#pragma once

#include "Scene.h"
#include "AssetManager.h"
#include "GameObject.h"
#include "./Component/Draw/SpriteRenderer.h"
#include "./Component/Draw/TextRenderer.h"


Scene::Scene() : 
	_gos()
{

}

void Scene::Init(std::shared_ptr<sf::RenderWindow> window)
{
	m_window = window;
}

void Scene::InitBackground()
{
	std::shared_ptr<GameObject> background = std::shared_ptr<GameObject>(new GameObject());
	std::shared_ptr<SpriteRenderer> spriteRenderer = std::shared_ptr<SpriteRenderer>(new SpriteRenderer());

	const sf::Texture& backgroundImage = AssetManager::GetInstance().GetTexture(SpriteType::BACKGROUND);
	spriteRenderer->SetTexture(backgroundImage);    
	spriteRenderer->SetPosition(sf::Vector2f(
		static_cast<float>(m_window->getSize().x) / 2.0f,
		static_cast<float>(m_window->getSize().y) / 2.0f
	));

	background->AddComponent(spriteRenderer);
	_gos.push_back(background);
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
	for (auto gameObject : _gos)
	{
		std::shared_ptr<SpriteRenderer> sprite = gameObject->GetComponent<SpriteRenderer>();

		if(sprite)
		{
			sprite->draw(target, states);
			continue;
		}

		std::shared_ptr<TextRenderer> text = gameObject->GetComponent<TextRenderer>();

		if(text)
		{
			text->draw(target, states);
			continue;
		}
	}
}
