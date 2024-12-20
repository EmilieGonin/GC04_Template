#pragma once

#include "CircleCollider.h"
#include "RectCollider.h"
#include "../Transform/TransformSFML.h"
#include "DebugCollider/DegubCollider.h"
#include "../../GameObject.h"

bool CircleCollider::CheckCollision(std::shared_ptr<Collider> other)
{
	auto circleCollider = std::dynamic_pointer_cast<CircleCollider>(other);
	if (circleCollider)
	{
		return CheckCollisionWithCircle(circleCollider);
	}
	auto rectCollider = std::dynamic_pointer_cast<RectCollider>(other);
	if (rectCollider)
	{
		return CheckCollisionWithRectangle(rectCollider);
	}
	return false;
}

void CircleCollider::Update()
{

}

void CircleCollider::Start()
{
	Collider::Start();

#ifdef ENABLE_DEBUG_MACRO
	InitDebugComponent();
#endif

}


bool CircleCollider::CheckCollisionWithCircle(std::shared_ptr<CircleCollider> other)
{
	sf::Vector2f pos = m_transform->getPosition();
	sf::Vector2f otherPos = other->m_transform->getPosition();
	
	float horizontalDist = (otherPos.x - pos.x) * (otherPos.x - pos.x);
	float verticalDist = (otherPos.y - pos.y) * (otherPos.y - pos.y);


	float distance = sqrt(horizontalDist + verticalDist);

	return (distance > m_radius + other->m_radius);
}

bool CircleCollider::CheckCollisionWithRectangle(std::shared_ptr<RectCollider> other)
{
	sf::Vector2f absCenter = other->GetRectBounds().getCenter() ;
	sf::Vector2f direction = (absCenter - m_transform->getPosition()).normalized();

	sf::Vector2f closestPoint = m_transform->getPosition() + direction * m_radius;


	return other->GetRectBounds().contains(closestPoint);
}
#ifdef ENABLE_DEBUG_MACRO
void CircleCollider::InitDebugComponent()
{
	std::shared_ptr<DebugCollider> debugShape = std::make_shared<DebugCollider>();

	std::shared_ptr<sf::CircleShape> circleShape = std::make_shared<sf::CircleShape>();
	circleShape->setFillColor(sf::Color::Transparent);
	circleShape->setOutlineColor(sf::Color::Green);
	circleShape->setOutlineThickness(1.f);
	circleShape->setRadius(m_radius);
	circleShape->setPosition(sf::Vector2f(-1, -1).normalized() * m_radius);
	debugShape->SetShape(circleShape);
	m_gameObject->AddComponent(debugShape);
}

void CircleCollider::EnabledDebugComponent(bool active)
{
	m_gameObject->GetComponent<DebugCollider>()->EnabledDebugCollider(active);
}
#endif
