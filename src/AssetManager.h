#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>

class AssetManager
{
public:
	AssetManager();

	sf::Font GetFont() const { return _font; }

private:
	const std::string _resPath = "resources/";
	sf::Font _font;
};