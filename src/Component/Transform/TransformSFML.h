#include "ATransform.h"
#include <SFML/System/Vector2.hpp>

class TransformSFML : public ATransform 
{

public:
    void setPosition(float x, float y) override;
    //const sf::Vector2f& getPosition();

private:
    sf::Vector2f position;

};
