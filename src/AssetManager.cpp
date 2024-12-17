#include "AssetManager.h"

std::string AssetManager::GetSpritePath(SpriteType type)
{
	auto it = _spritesPath.find(type);
	if (it != _spritesPath.end()) return it->second;
	return std::string();
}

AssetManager::AssetManager()
{
	if (!_font.openFromFile(_resPath + "Roboto-Regular.ttf"))
	{
		std::cerr << "Can't open font from file." << std::endl;
	}
}