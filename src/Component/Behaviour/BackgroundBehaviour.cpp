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
	std::shared_ptr<SpriteRenderer> spriteRenderer = m_gameObject->GetComponent<SpriteRenderer>();
	std::shared_ptr<sf::Texture> backgroundImage = AssetManager::GetInstance().GetTexture(TextureType::BACKGROUND);

	spriteRenderer->SetTexture(*backgroundImage);

	//sf::Vector2f origin = sf::Vector2f(0, 0);
	//spriteRenderer->SetPosition(origin);

	spriteRenderer->SetScale(windowSize);
}

void BackgroundBehaviour::Update()
{

}
