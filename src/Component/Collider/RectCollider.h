#include "Collider.h"

class RectCollider : public Collider
{

public:
    bool checkCollision(const Collider& other) override;

private:
    float width, height;
};