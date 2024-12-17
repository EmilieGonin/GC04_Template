#include "..\AComponent.h"

class Collider : public AComponent 
{

public:
    virtual bool CheckCollision(const Collider& other) = 0;

private:
    float m_radius;
};
