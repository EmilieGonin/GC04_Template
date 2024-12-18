#include "Collider.h"

class CircleCollider : public Collider
{

public:
     bool CheckCollision(const Collider& other) override;
     virtual void Update() override;

};