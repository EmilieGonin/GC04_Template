#pragma once

#include "CircleCollider.h"

bool CircleCollider::CheckCollision(const Collider& other)
{
	return false;
}

void CircleCollider::Update()
{

}

bool CircleCollider::CheckCollisionWithCircle(const CircleCollider& other)
{

	//auto distance = m_radius;

	return false;
}

bool CircleCollider::CheckCollisionWithRectangle(const RectCollider& other)
{
	return false;
}
