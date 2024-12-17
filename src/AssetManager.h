#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include <map>

#include "Singleton.h"

enum class SpriteType
{
    BALL,
    BRICK,
    PADDLE
};

class AssetManager : public Singleton<AssetManager>
{
public:
    sf::Font GetFont() const { return _font; }
    std::string GetSpritePath(SpriteType type);

private:
    AssetManager();
    ~AssetManager() = default;

    friend class Singleton<AssetManager>;

    const std::string _resPath = "resources/";
    const std::map<SpriteType, std::string> _spritesPath =
    {
        { SpriteType::BALL, "sprites/ball.svg" },
        { SpriteType::BRICK, "sprites/block.svg" },
        { SpriteType::PADDLE, "sprites/paddle.svg" }
    };

    sf::Font _font;
};