#include "..\AComponent.h"

class Collider : public AComponent 
{

public:
    virtual bool checkCollision(const Collider& other) = 0;

private:
    float radius;
};
