#include "BackgroundBehaviour.h"

#include <SFML/Graphics.hpp>
#include "../../AssetManager.h"
#include "../../GameObject.h"
#include "../Draw/SpriteRenderer.h"
#include <memory>

BackgroundBehaviour::BackgroundBehaviour()
{

}

void BackgroundBehaviour::Init(const sf::Vector2f& windowSize)
{
	std::shared_ptr<SpriteRenderer> spriteRenderer = std::shared_ptr<SpriteRenderer>(new SpriteRenderer());
	m_gameObject->AddComponent(spriteRenderer);

	std::shared_ptr<sf::Texture> backgroundImage = AssetManager::GetInstance().GetTexture(TextureType::BACKGROUND);
	spriteRenderer->SetTexture(*backgroundImage);

	std::shared_ptr<sf::Sprite> sprite = spriteRenderer->GetSprite();

	sf::IntRect rectDefault = sprite->getTextureRect();
	float ratioX = windowSize.x / (float)rectDefault.size.x;
	float ratioY = windowSize.y / (float)rectDefault.size.y;

	sprite->setScale(sf::Vector2f(ratioX, ratioY));
}

void BackgroundBehaviour::Update()
{

}
