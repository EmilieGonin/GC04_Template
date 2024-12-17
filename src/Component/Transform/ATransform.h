#include "..\AComponent.h"

class ATransform : public AComponent 
{

public:
    virtual void setPosition(float x, float y) = 0;

};
