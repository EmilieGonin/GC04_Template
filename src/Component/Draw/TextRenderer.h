#include "DrawableSFML.h"
#include <SFML/Graphics/Text.hpp>

class TextRenderer : public DrawableSFML 
{

public:
    void SetText(const std::string& text, const sf::Font& font, unsigned int size);
    void SetPosition(const sf::Vector2f& postion);

    // Hérité via Drawable
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:

private:
    sf::Text m_text;
    sf::Vector2f m_position;

};

