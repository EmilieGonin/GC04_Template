#include "Collider.h"

class RectCollider : public Collider
{

public:
    bool CheckCollision(const Collider& other) override;
    virtual void Update() override;

private:
    float m_width, m_height;
};