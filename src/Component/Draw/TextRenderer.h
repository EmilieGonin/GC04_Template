#include "DrawableSFML.h"
#include <SFML/Graphics/Text.hpp>

class TextRenderer : public DrawableSFML 
{

public:
    void draw() override;
    void setText(const std::string& text);

private:
    sf::Text text;

};

