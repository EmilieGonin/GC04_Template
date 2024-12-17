#include "DrawableSFML.h"
#include <SFML/Graphics/Sprite.hpp>

class SpriteRenderer : public DrawableSFML 
{

public:
    void draw() override;

private:
    sf::Sprite sprite;

};

