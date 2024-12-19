#pragma once
#include "ColliderSystem.h"

void ColliderSystem::AddCollider(std::shared_ptr<Collider> collider)
{
	m_colliders.push_back(collider);
}

void ColliderSystem::CheckCollisions()
{
	for (int i = 0; i < m_colliders.size(); i++)
	{
		for (int j = i + 1; j < m_colliders.size(); j++)
		{
			m_colliders[i]->ManageCollision(m_colliders[j]);
			m_colliders[j]->ManageCollision(m_colliders[i]);
		}
	}
}
