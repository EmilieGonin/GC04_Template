#pragma once

#include "../AComponent.h"
class Collider;

class BrickBehaviour : public AComponent
{

public:
	BrickBehaviour();
	virtual ~BrickBehaviour() = default;

	void Init();

	virtual void Update() override;
	virtual void Start() override;

private:

	void CollisionStarCallback(std::shared_ptr<Collider> other);
};