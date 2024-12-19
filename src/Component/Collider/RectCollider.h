#include <SFML/Graphics/Rect.hpp>
#include "Collider.h"

class CircleCollider;

class RectCollider : public Collider
{

public:
    bool CheckCollision(std::shared_ptr<Collider> other) override;
    virtual void Update() override;
    virtual void Start() override;

    sf::FloatRect GetRectBounds() const;

private:
#ifdef ENABLE_DEBUG_MACRO
    void InitDebugComponent();
#endif
    bool CheckCollisionWithCircle(std::shared_ptr<CircleCollider> other);
    bool CheckCollisionWithRectangle(std::shared_ptr<RectCollider> other);
    float m_width, m_height;
    sf::FloatRect m_rectBounds;

};