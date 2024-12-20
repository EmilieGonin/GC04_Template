#include <memory>
#include <SFML/Graphics.hpp>
#include "BrickBehaviour.h"

#include "../../AssetManager.h"
#include "../../GameObject.h"
#include "../Draw/SpriteRenderer.h"
#include "../Collider/RectCollider.h"
#include "../Behaviour/BallBehaviour.h"

using namespace std::placeholders;

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

	auto bindCollisionStart = std::bind(&BrickBehaviour::CollisionStarCallback, this, _1);
	collider->OnCollisionStart = bindCollisionStart;
}

void BrickBehaviour::CollisionStarCallback(std::shared_ptr<Collider> other)
{
	auto ball = other->GetGameObject()->GetComponent<BallBehaviour>();
	if (!ball)
	{
		return;
	}
	m_gameObject->GetComponent<Collider>()->m_isActive = false;
#ifdef ENABLE_DEBUG_MACRO
	m_gameObject->GetComponent<Collider>()->EnabledDebugComponent(false);
#endif
	m_gameObject->GetComponent<SpriteRenderer>()->GetSprite()->setColor(sf::Color::Transparent);

}
