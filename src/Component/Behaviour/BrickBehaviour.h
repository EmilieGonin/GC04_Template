#pragma once

#include "../AComponent.h"

class GameObject;

class BrickBehaviour : public AComponent
{

public:
	BrickBehaviour();
	virtual ~BrickBehaviour() = default;

	void Init();

	virtual void Update() override;

};