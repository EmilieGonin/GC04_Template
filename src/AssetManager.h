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
    const std::string GetSpritePath(SpriteType type);
    std::shared_ptr<sf::Texture> GetTexture(TextureType type);

    void LoadAssets();

private:
    AssetManager();
    ~AssetManager() = default;

    std::string GetPath(TextureType type);
    void LoadTextures();

    friend class Singleton<AssetManager>;

    std::map<TextureType, std::shared_ptr<sf::Texture>> m_textures;

    const std::string _resPath = "/resources/";
    const std::string m_mainFont = "Roboto-Regular.ttf";
    const std::map<SpriteType, std::string> m_texturesPath =
    {
        { SpriteType::BACKGROUND, "sprites/bg.png" },
        { SpriteType::BALL, "sprites/ball.png" },
        { SpriteType::BRICK, "sprites/block.png" },
        { SpriteType::PADDLE, "sprites/paddle.png" }
    };

    sf::Font m_font;
};