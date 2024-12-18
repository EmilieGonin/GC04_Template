#pragma once

#include "..\AComponent.h"

class ATransform : public AComponent 
{

public:
    virtual void Update() = 0;

};
