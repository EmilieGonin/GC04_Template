#include "TransformSFML.h"

void TransformSFML::SetPosition(float x, float y)
{
	m_position = sf::Vector2f(x, y);
}

//const sf::Vector2f& TransformSFML::getPosition()
//{
//	// TODO: insérer une instruction return ici
//}
