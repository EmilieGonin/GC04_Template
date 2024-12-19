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
	setScale(sf::Vector2f(x, y));
}

float TransformSFML::GetPositionX()
{
	return getPosition().x;
}

float TransformSFML::GetPositionY()
{
	return getPosition().y;
}

float TransformSFML::GetRotation()
{
	return getRotation().asDegrees();
}

float TransformSFML::GetScaleX()
{
	return getScale().x;
}

float TransformSFML::GetScaleY()
{
	return getScale().y;
}
