#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>

#include "Singleton.h"

class AssetManager : public Singleton<AssetManager>
{
public:
    sf::Font GetFont() const { return _font; }

private:
    AssetManager();
    ~AssetManager() = default;

    friend class Singleton<AssetManager>;

    const std::string _resPath = "resources/";
    sf::Font _font;
};