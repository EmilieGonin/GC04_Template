#include "Collider.h"

class CircleCollider : public Collider
{

public:
     bool checkCollision(const Collider& other) override;

};