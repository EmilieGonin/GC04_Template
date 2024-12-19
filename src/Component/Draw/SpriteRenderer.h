#pragma once

#include "DrawableSFML.h"
#pragma once

#include <SFML/Graphics/Sprite.hpp>

class SpriteRenderer : public DrawableSFML
{

public:
    SpriteRenderer();
    ~SpriteRenderer();

    void SetTexture(const sf::Texture& texture);
    void SetPosition(const sf::Vector2f& postion);
    void SetOrigin(const sf::Vector2f& origin);
    void SetScale(const sf::Vector2f& windowSize);

    // Hérité via Drawable
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:

private:
    std::shared_ptr<sf::Sprite> m_sprite;

};

