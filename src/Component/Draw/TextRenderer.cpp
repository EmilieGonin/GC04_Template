#pragma once

#include "TextRenderer.h"

/// <summary>
/// Set Text in TextRenderer Component
/// </summary>
/// <param name="text"></param>
/// <param name="font"></param>
/// <param name="size"></param>
void TextRenderer::SetText(const std::string& text, const sf::Font& font, unsigned int size) {

    m_text.setFont(font);
    m_text.setString(text);
    m_text.setCharacterSize(size);
}

void TextRenderer::SetPosition(const sf::Vector2f& postion)
{
    m_position = postion;
    m_text.setPosition(postion);
}

void TextRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_text, states);
}
