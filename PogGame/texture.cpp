#include "texture.h"

texture::texture(std::string path)
{
	m_renderer = graphics::INSTANCE()->renderer();
	m_texture = assets::INSTANCE()->getTexture(path.c_str());

	//Gets the Width and Height of the texture
	SDL_QueryTexture(m_texture, NULL, NULL, &m_width, &m_height);

	m_renderRect.w = m_width;
	m_renderRect.h = m_height;
}

texture::~texture()
{
	m_texture = NULL;
}

void texture::render(Vector2 pos, float rotation)
{
	//Centers the texture on the texture's world position so that its position is not the top left corner
	m_renderRect.x = (int)(pos.x - m_width);
	m_renderRect.y = (int)(pos.y - m_height);

	//Scales the width and height according to the scale of the GameEntity
	m_renderRect.w = (int)(m_width);
	m_renderRect.h = (int)(m_height);

	SDL_RenderCopyEx(m_renderer, m_texture, NULL, &m_renderRect, rotation, NULL, SDL_FLIP_NONE);
}
