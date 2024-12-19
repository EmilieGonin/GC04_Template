#include "Collider.h"

class RectCollider;
class CircleCollider : public Collider
{

public:
     bool CheckCollision(const Collider& other) override;
     virtual void Update() override;

     float m_radius;
private:


    bool CheckCollisionWithCircle(const CircleCollider& other);
    bool CheckCollisionWithRectangle(const RectCollider& other);
};