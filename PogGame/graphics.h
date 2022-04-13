/*----------
	graphic engine class
	handles all drawing to screen methods

	a. travis 22nd dec
----------*/
#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include "texture_helper.h"

class graphics
{
	private:
		static graphics* s_instance;

		SDL_Window* m_window;
		SDL_Renderer* m_renderer;

		int m_width;
		int m_height;

	public:
		static graphics* INSTANCE();

		graphics();
		~graphics();

		SDL_Renderer* renderer();

		void width(int w);
		int width();
		void height(int h);
		int height();

		bool init(const char* title, int w, int h, bool fullscreen);

		void clearBuffer();
		void render();
		void clean();
};
#endif