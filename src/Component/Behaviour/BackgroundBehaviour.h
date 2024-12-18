#pragma once

#include "../AComponent.h"

class BackgroundBehaviour : public AComponent
{

public:
	BackgroundBehaviour();
	virtual ~BackgroundBehaviour() = default;

	void Init(const sf::Vector2f& windowSize);

	virtual void Update() override;

};