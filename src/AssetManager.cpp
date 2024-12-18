#include "AssetManager.h"

std::shared_ptr<sf::Texture> AssetManager::GetTexture(TextureType type)
{
	auto it = m_textures.find(type);
	if (it != m_textures.end()) return it->second;
	return nullptr;
}

AssetManager::AssetManager()
{
	if (!m_font.openFromFile(m_resPath + "Roboto-Regular.ttf"))
	{
		std::cerr << "Can't open font from file." << std::endl;
	}

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