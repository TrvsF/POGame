#include "assets.h"

assets* assets::s_instance = NULL;

TTF_Font* assets::getFont(std::string path, int size)
{
	// allows for font indexing at different sizes
	std::string key = path + (char)size;

	if (m_fonts[key] == nullptr)
	{
		m_fonts[key] = TTF_OpenFont(path.c_str(), size);

		// if font cannot be opened
		if (m_fonts[key] == nullptr)
		{
			printf("cannot open font '%s' with error: %s\n", path.c_str(), TTF_GetError());
		}
	}

	return m_fonts[key];
}

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

SDL_Texture* assets::getText(std::string text, std::string path, int size, SDL_Color colour)
{
	TTF_Font* font = getFont(path, size);

	// key to store different types of text with same words colour etc
	std::string key = text + path + (char)size + (char)colour.r + (char)colour.b + (char)colour.g;

	if (m_textStrings[key] == nullptr)
	{
		m_textStrings[key] = texture_helper::loadText(font, text, colour);
	}

	return m_textStrings[key];
}

SDL_Texture* assets::getTexture(std::string path)
{
	// if texture is not loaded
	if (m_textures[path] == nullptr)
	{
		m_textures[path] = texture_helper::loadTexture(path);
	}

	return m_textures[path];
}
