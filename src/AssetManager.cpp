#pragma once

#include <filesystem>
#include "AssetManager.h"

AssetManager::AssetManager()
{
    auto currentPath = std::filesystem::current_path().string();

	if (!m_font.openFromFile(currentPath + m_resPath + "Roboto-Regular.ttf"))
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
    auto currentPath = std::filesystem::current_path().string();

	for (auto& sprite : m_texturesPath)
	{
		auto texture = std::make_shared<sf::Texture>();
		std::string path = currentPath + m_resPath + sprite.second;

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
const std::string AssetManager::GetSpritePath(TextureType type)
{
    auto it = m_texturesPath.find(type);
    if (it != m_texturesPath.end()) return it->second;
    return std::string();
}

/// <summary>
/// Get texture from SpriteType
/// </summary>
std::shared_ptr<sf::Texture> AssetManager::GetTexture(TextureType type)
{
    // If the texture is already loaded, it is returned
    if (m_textures.find(type) != m_textures.end())
    {
        return m_textures.at(type);
    }
    auto currentPath = std::filesystem::current_path().string();
    // Otherwise, it is loaded from the specified path
    sf::Texture texture;
    if (!texture.loadFromFile(currentPath + m_resPath + m_texturesPath.at(type)))
    {
        std::cerr << "Erreur : Impossible de charger le sprite : "
            << m_texturesPath.at(type) << std::endl;
    }

    // We insert the texture in the map and return it
    m_textures[type] = std::make_shared<sf::Texture>(texture);
    return m_textures.at(type);
}

/// <summary>
/// Load all textures initially
/// </summary>
void AssetManager::LoadAssets()
{
    for (const auto& [type, path] : m_texturesPath)
    {
        GetTexture(type); // Load and store each texture
    }

    std::cout << "Assets charg�s avec succ�s !" << std::endl;
}