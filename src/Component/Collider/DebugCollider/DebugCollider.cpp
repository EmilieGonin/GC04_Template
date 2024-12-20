#ifdef ENABLE_DEBUG_MACRO

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
	m_enabled = true;
}

void DebugCollider::SetShape(std::shared_ptr<sf::Shape> shape)
{
	m_shape = shape;
}

void DebugCollider::EnabledDebugCollider(bool enabled)
{
	m_enabled = enabled;
}

std::shared_ptr<sf::Shape> DebugCollider::GetShape()
{
	return m_shape;
}



void DebugCollider::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_shape == nullptr || !m_enabled)
	{
		return;
	}
	//m_transform->setPosition(sf::Vector2f(20, 20));
	//states.transform *= m_transform->getTransform();
	states.transform.combine(m_transform->getTransform());
	auto test = m_transform->getPosition();
	target.draw(*m_shape, states);
}
#endif
