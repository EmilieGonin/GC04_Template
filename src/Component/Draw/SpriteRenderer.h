#include "DrawableSFML.h"
#include <SFML/Graphics/Sprite.hpp>

class SpriteRenderer : public DrawableSFML 
{

public:
    void SetTexture(const sf::Texture& texture);
    void Draw() override;

private:
    sf::Sprite m_sprite;

};

