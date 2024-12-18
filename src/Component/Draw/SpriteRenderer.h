#include "DrawableSFML.h"
#include <SFML/Graphics/Sprite.hpp>

class SpriteRenderer : public DrawableSFML 
{

public:
    SpriteRenderer();
    ~SpriteRenderer();

    void SetTexture(const sf::Texture& texture);
    void SetPosition(const sf::Vector2f& postion);

    // Hérité via Drawable
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:

private:
    std::shared_ptr<sf::Sprite> m_sprite;
    sf::Vector2f m_position;

};

