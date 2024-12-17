#include "Collider.h"

class RectCollider : public Collider
{

public:
    bool CheckCollision(const Collider& other) override;

private:
    float m_width, m_height;
};