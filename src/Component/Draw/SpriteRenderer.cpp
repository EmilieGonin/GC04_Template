#pragma once
#include "SpriteRenderer.h"
#include <memory>


SpriteRenderer::SpriteRenderer() : 
    m_position(0, 0),
    m_sprite()
{

}

SpriteRenderer::~SpriteRenderer()
{

}

void SpriteRenderer::SetTexture(const sf::Texture& texture)
{
    // Create a sprite if necessary
    if (!m_sprite) 
    {
        m_sprite = std::make_shared<sf::Sprite>(texture);
    }

    m_sprite->setTexture(texture, true);

    //m_sprite->setTextureRect(sf::IntRect({ 0,0 }, { 1600, 900 }));
    //m_sprite->setScale(sf::Vector2f(1600, 900));
}

void SpriteRenderer::SetPosition(const sf::Vector2f& position)
{
    m_position = position;

    if (m_sprite) 
    {
        m_sprite->setPosition(position);
    }
}

void SpriteRenderer::SetScale(const sf::Vector2f& windowSize)
{
    sf::IntRect rectDefault = m_sprite->getTextureRect();
    float ratioX = windowSize.x / (float)rectDefault.size.x;
    float ratioY = windowSize.y / (float)rectDefault.size.y;

    // Utiliser le plus petit rapport pour garder l'aspect
    float scaleFactor = std::min(ratioX, ratioY);
    m_sprite->setScale(sf::Vector2f(scaleFactor, scaleFactor));
}

void SpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (m_sprite) 
    {
        target.draw(*m_sprite, states);
    }
}
