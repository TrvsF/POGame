#pragma once
#include "game_entity.h"
#include "assets.h"

class texture
{
	protected:
		SDL_Renderer* m_renderer;
		SDL_Texture* m_texture;

		int m_width;
		int m_height;

		SDL_Rect m_renderRect;

	public:
		texture(std::string path);
		~texture();

		virtual void render(Vector2 pos);
	
};