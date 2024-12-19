#pragma once

#include "ATransform.h"
#include <SFML/System/Vector2.hpp>

class TransformSFML : public ATransform , public sf::Transformable
{

public:
    virtual void Update() override;
    virtual void SetPosition(float x, float y) override;
    virtual void SetRotation(float angle) override;
    virtual void SetScale(float x, float y) override;
    virtual float GetPositionX() override;
    virtual float GetPositionY() override;
    virtual float GetRotation() override;
    virtual float GetScaleX() override;
    virtual float GetScaleY() override;
};
