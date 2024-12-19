#include "BrickBehaviour.h"

#include <SFML/Graphics.hpp>
#include "../../AssetManager.h"
#include "../../GameObject.h"
#include "../Draw/SpriteRenderer.h"
#include <memory>

BrickBehaviour::BrickBehaviour()
{

}

void BrickBehaviour::Init()
{
	std::shared_ptr<SpriteRenderer> spriteRenderer = std::shared_ptr<SpriteRenderer>(new SpriteRenderer());
	m_gameObject->AddComponent(spriteRenderer);

	std::shared_ptr<sf::Texture> backgroundImage = AssetManager::GetInstance().GetTexture(TextureType::BRICK);
	spriteRenderer->SetTexture(*backgroundImage);
}

void BrickBehaviour::Update()
{

}
