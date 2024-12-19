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
	std::shared_ptr<DebugCollider> debugShape = std::make_shared<DebugCollider>();
	std::shared_ptr<sf::CircleShape> circleShape = std::make_shared<sf::CircleShape>();
	circleShape->setFillColor(sf::Color::Transparent);
	circleShape->setOutlineColor(sf::Color::Green);
	circleShape->setOutlineThickness(1.f);
	circleShape->setRadius(m_radius);
	debugShape->SetShape(circleShape);
	m_gameObject->AddComponent(debugShape);
#endif

}


bool CircleCollider::CheckCollisionWithCircle(std::shared_ptr<CircleCollider> other)
{
	sf::Vector2f pos = sf::Vector2f(m_transform->GetPositionX(), m_transform->GetPositionY());
	sf::Vector2f otherPos = sf::Vector2f(other->m_transform->GetPositionX(), other->m_transform->GetPositionY());
	
	float horizontalDist = (otherPos.x - pos.x) * (otherPos.x - pos.x);
	float verticalDist = (otherPos.y - pos.y) * (otherPos.y - pos.y);


	float distance = sqrt(horizontalDist + verticalDist);

	return (distance > m_radius + other->m_radius);
}

bool CircleCollider::CheckCollisionWithRectangle(std::shared_ptr<RectCollider> other)
{
	sf::Vector2f position = sf::Vector2f(m_transform->GetPositionX(), m_transform->GetPositionY());
	sf::Vector2f absCenter = other->GetRectBounds().getCenter() + position;
	sf::Vector2f direction = (absCenter - position).normalized();

	sf::Vector2f closestPoint = position + direction * m_radius;


	return other->GetRectBounds().contains(closestPoint);
}
#ifdef ENABLE_DEBUG_MACRO
void CircleCollider::InitDebugComponent()
{
}
#endif
