#pragma once

#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include <map>

#include "Singleton.h"

enum class TextureType
{
    BACKGROUND,
    BALL,
    BRICK,
    PADDLE
};

class AssetManager : public Singleton<AssetManager>
{
public:
    // Accessors
    const sf::Font GetFont() const { return m_font; }
    const std::string GetSpritePath(TextureType type);
    std::shared_ptr<sf::Texture> GetTexture(TextureType type);

    void LoadAssets();

private:
    AssetManager();
    ~AssetManager() = default;

    std::string GetPath(TextureType type);
    void LoadTextures();

    friend class Singleton<AssetManager>;

    const std::string m_resPath = "/resources/";
    const std::string m_mainFont = "Roboto-Regular.ttf";
    const std::map<TextureType, std::string> m_texturesPath =
    {
        { TextureType::BACKGROUND, "sprites/bg.png" },
        { TextureType::BALL, "sprites/ball.png" },
        { TextureType::BRICK, "sprites/block.png" },
        { TextureType::PADDLE, "sprites/paddle.png" }
    };

    sf::Font m_font;
    std::map<TextureType, std::shared_ptr<sf::Texture>> m_textures;
};