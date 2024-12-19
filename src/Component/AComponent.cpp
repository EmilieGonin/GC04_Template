#pragma once
#include "AComponent.h"

void AComponent::Start()
{
	if (m_isStarted)
	{
		return;
	}
	m_isStarted = true;
}

void AComponent::Init(std::shared_ptr<GameObject> gameObject)
{
	m_gameObject = gameObject;
}

std::shared_ptr<GameObject> AComponent::GetGameObject()
{
	return m_gameObject;
}
