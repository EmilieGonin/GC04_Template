#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include "RectCollider.h"
#include "CircleCollider.h"

bool RectCollider::CheckCollision(const Collider& other)
{
	auto circleCollider = dynamic_cast<const CircleCollider&>(other);

	return false;
}

void RectCollider::Update()
{

}

sf::FloatRect RectCollider::GetRectBounds() const
{
	return m_rectBounds;
}

bool RectCollider::CheckCollisionWithCircle(const CircleCollider& other)
{
	sf::CircleShape circle;
	return false;
}

bool RectCollider::CheckCollisionWithRectangle(const RectCollider& other)
{
	auto intersection = other.GetRectBounds().findIntersection(m_rectBounds);
	return intersection != std::nullopt;
}
