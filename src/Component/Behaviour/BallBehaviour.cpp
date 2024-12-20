#pragma once

#include "BallBehaviour.h"
#include "../Transform/TransformSFML.h"
#include "../../AssetManager.h"
#include "../../GameObject.h"
#include "../Draw/SpriteRenderer.h"
#include "../Collider/RectCollider.h"
#include "../Collider/CircleCollider.h"
#include "../Transform/TransformSFML.h"
#include "../../App.h"
#include "../../EventSystem.h"

using namespace std::placeholders;

BallBehaviour::BallBehaviour()
{
}

BallBehaviour::~BallBehaviour()
{
}

void BallBehaviour::Update()
{
	m_transform->move(m_direction * 2.f);
}

void BallBehaviour::Start()
{
	m_transform = m_gameObject->GetComponent<TransformSFML>();

	m_transform->setPosition(sf::Vector2f(600, 700));

	std::shared_ptr<SpriteRenderer> spriteRenderer = std::shared_ptr<SpriteRenderer>(new SpriteRenderer());
	m_gameObject->AddComponent(spriteRenderer);
	std::shared_ptr<sf::Texture> backgroundImage = AssetManager::GetInstance().GetTexture(TextureType::BALL);
	spriteRenderer->SetTexture(*backgroundImage);

	m_collider = std::make_shared<CircleCollider>();
	m_collider->m_radius = spriteRenderer->GetSprite()->getGlobalBounds().size.x/2;
	spriteRenderer->GetSprite()->setOrigin(sf::Vector2f(m_collider->m_radius, m_collider->m_radius));
	m_gameObject->AddComponent(m_collider);

	SetDirection(sf::Vector2f(1, -1));

	auto collisionStarBind = std::bind(&BallBehaviour::CollisionStartCallback, this, _1);
	m_collider->OnCollisionStart = collisionStarBind;
}

void BallBehaviour::SetDirection(sf::Vector2f newDir)
{
	m_direction = newDir.normalized();
}

void BallBehaviour::CollisionStartCallback(std::shared_ptr<Collider> other)
{
	std::shared_ptr<RectCollider> otherCasted = std::dynamic_pointer_cast<RectCollider>(other);
	if (!otherCasted || !other->m_isActive)
	{
		return;
	}


	auto otherCenter = otherCasted->GetRectBounds().getCenter();
	if (otherCenter.x - otherCasted->GetRectBounds().size.x / 2 > m_transform->getPosition().x ||
		otherCenter.x + otherCasted->GetRectBounds().size.x / 2 < m_transform->getPosition().x)
	{
		m_direction.x = -m_direction.x;
	}
	if (otherCenter.y - otherCasted->GetRectBounds().size.y / 2 > m_transform->getPosition().y ||
		otherCenter.y + otherCasted->GetRectBounds().size.y / 2 < m_transform->getPosition().y)
	{
		m_direction.y = -m_direction.y;
	}
}
