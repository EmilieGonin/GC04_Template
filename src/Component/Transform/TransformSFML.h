#include "ATransform.h"
#include <SFML/System/Vector2.hpp>

class TransformSFML : public ATransform 
{

public:
    virtual void SetPosition(float x, float y) override;
    virtual void Update() override;
    //const sf::Vector2f& getPosition();

private:
    sf::Vector2f m_position;

};
