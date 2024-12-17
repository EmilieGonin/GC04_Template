#include "DrawableSFML.h"
#include <SFML/Graphics/Text.hpp>

class TextRenderer : public DrawableSFML 
{

public:
    void Draw() override;
    void SetText(const std::string& text, const sf::Font& font, unsigned int size);

private:
    sf::Text m_text;

};

