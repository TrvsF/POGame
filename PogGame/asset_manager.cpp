#include "asset_manager.h"

asset_manager* asset_manager::s_instance = NULL;

asset_manager* asset_manager::INSTANCE()
{
	if (s_instance == NULL)
		s_instance = new asset_manager();

	return s_instance;
}

asset_manager::asset_manager()
{
}

asset_manager::~asset_manager()
{
	for (auto texture : m_textures)
	{
		if (texture.second != NULL)
		{
			SDL_DestroyTexture(texture.second);
		}
	}
	m_textures.clear();
}

SDL_Texture* asset_manager::getTexture(const char* path)
{
	// if texture is not loaded
	if (m_textures[path] == nullptr)
	{
		m_textures[path] = texture_helper::loadTexture(path);
	}

	return m_textures[path];
}
