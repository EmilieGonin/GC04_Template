#include "Collider.h"

class RectCollider;
class CircleCollider : public Collider
{

public:
     bool CheckCollision(std::shared_ptr<Collider> other) override;
     virtual void Update() override;
     virtual void Start() override;
     float m_radius;
private:
#ifdef ENABLE_DEBUG_MACRO
    void InitDebugComponent();
#endif

    bool CheckCollisionWithCircle(std::shared_ptr<CircleCollider> other);
    bool CheckCollisionWithRectangle(std::shared_ptr<RectCollider> other);
};