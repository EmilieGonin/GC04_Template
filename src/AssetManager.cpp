#include "AssetManager.h"

AssetManager::AssetManager()
{
	if (!_font.openFromFile(_resPath + "Roboto-Regular.ttf"))
	{
		std::cerr << "Can't open font from file." << std::endl;
	}
}