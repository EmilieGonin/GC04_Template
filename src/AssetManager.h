#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include <map>

#include "Singleton.h"

enum class TextureType
{
    BALL,
    BRICK,
    PADDLE
};

class AssetManager : public Singleton<AssetManager>
{
public:
    sf::Font GetFont() const { return m_font; }
    std::shared_ptr<sf::Texture> GetTexture(TextureType type);

private:
    AssetManager();
    ~AssetManager() = default;

    std::string GetPath(TextureType type);
    void LoadTextures();

    friend class Singleton<AssetManager>;

    const std::string m_resPath = "resources/";
    const std::string m_mainFont = "Roboto-Regular.ttf";
    const std::map<TextureType, std::string> m_texturesPath =
    {
        { TextureType::BALL, "sprites/ball.png" },
        { TextureType::BRICK, "sprites/block.png" },
        { TextureType::PADDLE, "sprites/paddle.png" }
    };

    std::map<TextureType, std::shared_ptr<sf::Texture>> m_textures;

    sf::Font m_font;
};