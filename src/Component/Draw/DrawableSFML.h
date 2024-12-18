#pragma once
#include "ADrawable.h"
#include <SFML/Graphics.hpp>

class DrawableSFML : public ADrawable, public sf::Drawable
{

public:
	DrawableSFML();
	virtual ~DrawableSFML();

	// Hérité via Drawable
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

protected:

};
