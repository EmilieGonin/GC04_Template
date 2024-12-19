#include "BrickBehaviour.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "../../AssetManager.h"
#include "../../GameObject.h"
#include "../Draw/SpriteRenderer.h"
#include "../Collider/RectCollider.h"
#include "../Transform/ATransform.h"
#include <memory>

BrickBehaviour::BrickBehaviour()
{

}

void BrickBehaviour::Init()
{
	std::shared_ptr<ATransform> transform = m_gameObject->GetComponent<ATransform>();

	// SPRITE
	std::shared_ptr<SpriteRenderer> spriteRenderer = std::shared_ptr<SpriteRenderer>(new SpriteRenderer());
	m_gameObject->AddComponent(spriteRenderer);

	std::shared_ptr<sf::Texture> backgroundImage = AssetManager::GetInstance().GetTexture(TextureType::BRICK);
	spriteRenderer->SetTexture(*backgroundImage);

	transform->m_width = backgroundImage->getSize().x;
	transform->m_height = backgroundImage->getSize().y;

	// RECT COLLIDER

	std::shared_ptr<RectCollider> rectCollider = std::shared_ptr<RectCollider>(new RectCollider());
	m_gameObject->AddComponent(rectCollider);
}

void BrickBehaviour::Update()
{

}
