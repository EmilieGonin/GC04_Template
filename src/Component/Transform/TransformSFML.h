#include "ATransform.h"
#include <SFML/System/Vector2.hpp>

class TransformSFML : public ATransform 
{

public:
    void SetPosition(float x, float y) override;
    //const sf::Vector2f& getPosition();

private:
    sf::Vector2f m_position;

};
