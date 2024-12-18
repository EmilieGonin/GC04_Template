#include "..\AComponent.h"

class ATransform : public AComponent 
{

public:
    virtual void SetPosition(float x, float y) = 0;
    virtual void Update() = 0;

};
