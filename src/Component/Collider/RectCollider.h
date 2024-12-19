#include <SFML/Graphics/Rect.hpp>
#include "Collider.h"

class CircleCollider;

class RectCollider : public Collider
{

public:
    bool CheckCollision(const Collider& other) override;
    virtual void Update() override;

    sf::FloatRect GetRectBounds() const;

private:
    bool CheckCollisionWithCircle(const CircleCollider& other);
    bool CheckCollisionWithRectangle(const RectCollider& other);
    float m_width, m_height;
    sf::FloatRect m_rectBounds;
};