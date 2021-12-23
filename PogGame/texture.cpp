#include "texture.h"

texture::texture(std::string path)
{
	m_renderer = graphics::INSTANCE()->renderer();
	m_texture = asset_manager::INSTANCE()->getTexture(path.c_str());

	//Gets the Width and Height of the texture
	SDL_QueryTexture(m_texture, NULL, NULL, &m_width, &m_height);

	m_renderRect.w = m_width;
	m_renderRect.h = m_height;
}

texture::~texture()
{
	m_texture = NULL;
}

void texture::render()
{
	SDL_RenderCopy(m_renderer, m_texture, NULL, &m_renderRect);
}
