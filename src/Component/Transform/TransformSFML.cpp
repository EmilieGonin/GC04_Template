#pragma once

#include "TransformSFML.h"

void TransformSFML::Update()
{

}

void TransformSFML::SetPosition(float x, float y)
{
	setPosition(sf::Vector2f(x, y));
}

void TransformSFML::SetRotation(float angle)
{
	//TODO
}

void TransformSFML::SetScale(float x, float y)
{
	setPosition(sf::Vector2f(x, y));
}
