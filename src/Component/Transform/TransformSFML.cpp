#pragma once

#include "TransformSFML.h"

void TransformSFML::SetPosition(float x, float y)
{
	m_position = sf::Vector2f(x, y);
}

void TransformSFML::Update()
{

}

//const sf::Vector2f& TransformSFML::getPosition()
//{
//	// TODO: insérer une instruction return ici
//}
