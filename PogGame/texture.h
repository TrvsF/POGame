#pragma once
#include "game_entity.h"
#include "graphics.h"

class texture
{
	protected:
		SDL_Texture* m_texture;

		SDL_Renderer* m_renderer;

		int m_width;
		int m_height;

		SDL_Rect m_renderRect;

	public:
		texture(const char* path, SDL_Renderer* renderer);
		~texture();

		virtual void render();
	
};