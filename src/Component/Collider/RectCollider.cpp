#pragma once



#include <SFML/Graphics/CircleShape.hpp>
#include "RectCollider.h"
#include "CircleCollider.h"
#include "../../GameObject.h"
#include "../Transform/TransformSFML.h"
#include "DebugCollider/DegubCollider.h"



bool RectCollider::CheckCollision(std::shared_ptr<Collider> other)
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

void RectCollider::Update()
{
	m_rectBounds.position = m_transform->getPosition();
}

void RectCollider::Start() {

#ifdef ENABLE_DEBUG_MACRO
	InitDebugComponent();
#endif // ENABLE_DEBUG_MACRO

}

sf::FloatRect RectCollider::GetRectBounds() const
{
	return m_rectBounds;
}


bool RectCollider::CheckCollisionWithCircle(std::shared_ptr<CircleCollider> other)
{
	std::shared_ptr<TransformSFML> transformOther = other->GetTransform();

	sf::Vector2f absCenter = m_rectBounds.getCenter() + transformOther->getPosition();
	sf::Vector2f direction = (absCenter - transformOther->getPosition()).normalized();

	sf::Vector2f closestPoint = transformOther->getPosition() + direction * other->m_radius;


	return m_rectBounds.contains(closestPoint);
}

bool RectCollider::CheckCollisionWithRectangle(std::shared_ptr<RectCollider> other)
{
	auto intersection = other->GetRectBounds().findIntersection(m_rectBounds);
	return intersection != std::nullopt;
}


#ifdef ENABLE_DEBUG_MACRO
void RectCollider::InitDebugComponent()
{
	std::shared_ptr<DebugCollider> debugShape = std::make_shared<DebugCollider>();
	std::shared_ptr<sf::RectangleShape> rectangleShape = std::make_shared<sf::RectangleShape>();
	rectangleShape->setFillColor(sf::Color::Transparent);
	rectangleShape->setOutlineColor(sf::Color::Green);
	rectangleShape->setSize(m_rectBounds.size);
	debugShape->SetShape(rectangleShape);
	m_gameObject->AddComponent(debugShape);
}
#endif // ENABLE_DEBUG_MACRO
