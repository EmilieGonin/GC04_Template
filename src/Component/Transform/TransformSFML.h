#include "ATransform.h"
#include <SFML/System/Vector2.hpp>

class TransformSFML : public ATransform , public sf::Transformable
{

public:
    virtual void Update() override;
};
