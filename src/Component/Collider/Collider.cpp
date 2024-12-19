#include "Collider.h"

void Collider::ManageCollision(std::shared_ptr<Collider> other)
{
	auto it = std::find(m_currentCollisions.begin(), 
		m_currentCollisions.end(), other);
	bool wasCollidingLastFrame = it != m_currentCollisions.end();

	if (!CheckCollision(*other))
	{
		if (wasCollidingLastFrame)
		{
			if (OnCollisionEnd) OnCollisionEnd(other);
		}
		m_currentCollisions.erase(it);
		return;
	}

	if (wasCollidingLastFrame)
	{
		if (OnCollisionUpdate) OnCollisionUpdate(other);
		return;
	}

	m_currentCollisions.push_back(other);
	if (OnCollisionStart) OnCollisionStart(other);

}