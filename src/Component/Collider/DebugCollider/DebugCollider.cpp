#pragma once

#include "DegubCollider.h"
#include "../../../GameObject.h"
#include "../../Transform/TransformSFML.h"

DebugCollider::DebugCollider() : m_shape(nullptr)
{
}

DebugCollider::~DebugCollider()
{
}

void DebugCollider::Start()
{
	m_transform = m_gameObject->GetComponent<TransformSFML>();
}

void DebugCollider::SetShape(std::shared_ptr<sf::Shape> shape)
{
	m_shape = shape;
}

std::shared_ptr<sf::Shape> DebugCollider::GetShape()
{
	return m_shape;
}



void DebugCollider::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_shape == nullptr)
	{
		return;
	}
	states.transform *= m_transform->getTransform();
	target.draw(*m_shape, states);
}
