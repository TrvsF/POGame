#pragma once
#include "game_entity.h"
#include "assets.h"
/*----------
	texture class
	object given to all drawable game entities so the may be drawn on screen

	a. travis 22nd dec
----------*/
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

		// probably not a good idea to use this for collison but atm i dont see anything wrong with it
		int width();
		int height();

		virtual void render(Vector2 pos, float rotation);
};