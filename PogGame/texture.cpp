#include "texture.h"

texture::texture(const char* path, SDL_Renderer* renderer)
{
	m_renderer = renderer;

	m_texture = texture_helper::loadTexture(path, m_renderer);

	//Gets the Width and Height of the texture
	SDL_QueryTexture(m_texture, NULL, NULL, &m_width, &m_height);

	m_renderRect.w = m_width;
	m_renderRect.h = m_height;
}

texture::~texture()
{
	SDL_DestroyTexture(m_texture);
	m_texture = NULL;
}

void texture::render()
{
	SDL_RenderCopy(m_renderer, m_texture, NULL, &m_renderRect);
}
