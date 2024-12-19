#pragma once
#include "SpriteRenderer.h"
#include <memory>


SpriteRenderer::SpriteRenderer() :
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
    if (m_sprite) 
    {
        m_sprite->setPosition(position);
    }
}

void SpriteRenderer::SetOrigin(const sf::Vector2f& origin)
{
    if (m_sprite) 
    {
        m_sprite->setOrigin(origin);
    }
}

void SpriteRenderer::SetScale(const sf::Vector2f& windowSize)
{
    m_sprite->setScale(windowSize);
}

std::shared_ptr<sf::Sprite> SpriteRenderer::GetSprite()
{
    return m_sprite;
}

void SpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (m_sprite) 
    {
        target.draw(*m_sprite, states);
    }
}
