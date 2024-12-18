#include "ATransform.h"
#include <SFML/System/Vector2.hpp>

class TransformSFML : public ATransform , public sf::Transformable
{

public:
    virtual void Update() override;
    virtual void SetPosition(float x, float y) override;
    virtual void SetRotation(float angle) override;
    virtual void SetScale(float x, float y) override;
};
