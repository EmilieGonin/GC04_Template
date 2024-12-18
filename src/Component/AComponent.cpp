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
