#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "texture.h"
/*----------
	graphic engine class
	handles all drawing to screen methods

	a. travis 22nd dec
----------*/
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