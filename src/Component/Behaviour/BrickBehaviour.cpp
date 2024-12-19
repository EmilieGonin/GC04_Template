#include <memory>
#include <SFML/Graphics.hpp>
#include "BrickBehaviour.h"

#include "../../AssetManager.h"
#include "../../GameObject.h"
#include "../Draw/SpriteRenderer.h"
#include "../Collider/RectCollider.h"

BrickBehaviour::BrickBehaviour()
{

}

void BrickBehaviour::Init()
{
	

	


}

void BrickBehaviour::Update()
{

}

void BrickBehaviour::Start()
{
	std::shared_ptr<SpriteRenderer> spriteRenderer = std::shared_ptr<SpriteRenderer>(new SpriteRenderer());
	m_gameObject->AddComponent(spriteRenderer);

	std::shared_ptr<sf::Texture> backgroundImage = AssetManager::GetInstance().GetTexture(TextureType::BRICK);
	spriteRenderer->SetTexture(*backgroundImage);

	auto collider = std::make_shared<RectCollider>();
	collider->SetRectBounds(spriteRenderer->GetSprite()->getLocalBounds());
	m_gameObject->AddComponent(collider);
}
