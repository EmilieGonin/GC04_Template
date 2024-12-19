#pragma once

#include "..\AComponent.h"

class ATransform : public AComponent
{

public:
    virtual void Update() = 0;
    virtual void SetPosition(float x, float y) = 0;
    virtual void SetRotation(float angle) = 0;
    virtual void SetScale(float x, float y) = 0;
};
