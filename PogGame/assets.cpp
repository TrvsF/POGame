#include "assets.h"

assets* assets::s_instance = NULL;

assets* assets::INSTANCE()
{
	if (s_instance == NULL)
		s_instance = new assets();

	return s_instance;
}

assets::assets()
{
}

assets::~assets()
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

SDL_Texture* assets::getTexture(const char* path)
{
	// if texture is not loaded
	if (m_textures[path] == nullptr)
	{
		m_textures[path] = texture_helper::loadTexture(path);
	}

	return m_textures[path];
}
