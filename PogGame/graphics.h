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
#include "texture.h"

class graphics
{
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;

		static graphics* s_instance;

	public:
		static graphics* INSTANCE();

		graphics();
		~graphics();

		bool init(const char* title, int xPos, int yPos, int width, int hieght, bool fullscreen);
		SDL_Renderer* renderer();

		void drawCircle(int centreX, int centreY, int radius);
		void clearBuffer();
		void render();
		void clean();
};
#endif