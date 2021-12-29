#include "texture.h"

texture::texture(std::string path)
{
	m_renderer = graphics::INSTANCE()->renderer();
	m_texture = assets::INSTANCE()->getTexture(path.c_str());

	SDL_QueryTexture(m_texture, NULL, NULL, &m_width, &m_height);

	m_renderRect.w = m_width;
	m_renderRect.h = m_height;
}

texture::~texture()
{
	m_texture = NULL;
}

int texture::width()
{
	return m_width;
}

int texture::height()
{
	return m_height;
}

void texture::render(Vector2 pos, float rotation)
{
	m_renderRect.x = (int)(pos.x - m_width);
	m_renderRect.y = (int)(pos.y - m_height);

	m_renderRect.w = (int)(m_width);
	m_renderRect.h = (int)(m_height);

	SDL_RenderCopyEx(m_renderer, m_texture, NULL, &m_renderRect, rotation, NULL, SDL_FLIP_NONE);
}
