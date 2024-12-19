#pragma once
#include <filesystem>
#include "AssetManager.h"

std::shared_ptr<sf::Texture> AssetManager::GetTexture(TextureType type)
{
	auto it = m_textures.find(type);
	if (it != m_textures.end()) return it->second;
	return nullptr;
}

AssetManager::AssetManager()
{
    auto currentPath = std::filesystem::current_path().string();

	if (!_font.openFromFile(currentPath + _resPath + "Roboto-Regular.ttf"))
	{
		std::cerr << "[" << m_mainFont << "] Font not loaded." << std::endl;
	}
	else std::cout << "[" << m_mainFont << "] Font loaded." << std::endl;

	LoadTextures();
}

std::string AssetManager::GetPath(TextureType type)
{
	auto it = m_texturesPath.find(type);
	if (it != m_texturesPath.end()) return it->second;
	return std::string();
}

void AssetManager::LoadTextures()
{
	for (auto& sprite : m_texturesPath)
	{
		auto texture = std::make_shared<sf::Texture>();
		std::string path = m_resPath + sprite.second;

		if (!texture->loadFromFile(path))
		{
			std::cerr << "Texture not loaded at path : " << path << std::endl;
		}
		else std::cout << "Texture loaded at path " << path << std::endl;
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

    std::cout << "Assets charg�s avec succ�s !" << std::endl;
}