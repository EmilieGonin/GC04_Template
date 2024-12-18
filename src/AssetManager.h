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

    const std::string _resPath = "resources/";
    const std::map<SpriteType, std::string> _spritesPath =
    {
        { SpriteType::BACKGROUND, "Roboto-Regular.ttf" },
        { SpriteType::BALL, "sprites/ball.svg" },
        { SpriteType::BRICK, "sprites/block.svg" },
        { SpriteType::PADDLE, "sprites/paddle.svg" }
    };

    sf::Font _font;
    std::map<SpriteType, sf::Texture> _textures;
};