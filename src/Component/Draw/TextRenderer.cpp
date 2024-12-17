#include "TextRenderer.h"

void TextRenderer::Draw()
{
	//App::GetInstance()->m_window->display(text);
}

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
