#pragma once
#include <filesystem>
#include "AssetManager.h"


AssetManager::AssetManager()
{
    auto currentPath = std::filesystem::current_path().string();

	if (!_font.openFromFile(currentPath + _resPath + "Roboto-Regular.ttf"))
	{
		std::cerr << "Can't open font from file." << std::endl;
	}
}

/// <summary>
/// Get path from SpriteType
/// </summary>
const std::string AssetManager::GetSpritePath(SpriteType type)
{
    auto it = _spritesPath.find(type);
    if (it != _spritesPath.end()) return it->second;
    return std::string();
}

/// <summary>
/// Get texture from SpriteType
/// </summary>
const sf::Texture& AssetManager::GetTexture(SpriteType type)
{
    // If the texture is already loaded, it is returned
    if (_textures.find(type) != _textures.end())
    {
        return _textures.at(type);
    }
    auto currentPath = std::filesystem::current_path().string();
    // Otherwise, it is loaded from the specified path
    sf::Texture texture;
    if (!texture.loadFromFile(currentPath + _resPath + _spritesPath.at(type)))
    {
        std::cerr << "Erreur : Impossible de charger le sprite : "
            << _spritesPath.at(type) << std::endl;
    }

    // We insert the texture in the map and return it
    _textures[type] = texture;
    return _textures.at(type);
}

/// <summary>
/// Load all textures initially
/// </summary>
void AssetManager::LoadAssets()
{
    for (const auto& [type, path] : _spritesPath)
    {
        GetTexture(type); // Load and store each texture
    }

    std::cout << "Assets chargés avec succès !" << std::endl;
}