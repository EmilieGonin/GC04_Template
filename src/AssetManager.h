#pragma once

#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include <map>

#include "Singleton.h"

enum class SpriteType
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
    const sf::Font GetFont() const { return _font; }
    const std::string GetSpritePath(SpriteType type);
    const sf::Texture& GetTexture(SpriteType type);

    void LoadAssets();

private:
    AssetManager();
    ~AssetManager() = default;

    friend class Singleton<AssetManager>;

    const std::string _resPath = "/resources/";
    const std::map<SpriteType, std::string> _spritesPath =
    {
        { SpriteType::BACKGROUND, "sprites/bg.png" },
        { SpriteType::BALL, "sprites/ball.png" },
        { SpriteType::BRICK, "sprites/block.png" },
        { SpriteType::PADDLE, "sprites/paddle.png" }
    };

    sf::Font _font;
    std::map<SpriteType, sf::Texture> _textures;
};