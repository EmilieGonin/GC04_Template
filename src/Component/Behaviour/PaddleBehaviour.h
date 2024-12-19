#pragma once

#include "../AComponent.h"
#include "../../EventSystem.h"

class GameObject;

class PaddleBehaviour : public AComponent
{
	int m_speed;

public:
	PaddleBehaviour();
	virtual ~PaddleBehaviour() = default;

	void Init(std::shared_ptr<EventSystem> eventSystem);

	virtual void Update() override;
	void Move(int value);
};