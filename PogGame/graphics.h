#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "player_object.h"
#include <iostream>

class graphics
{
public:
	graphics();
	~graphics();

	bool init(const char* title, int xPos, int yPos, int width, int hieght, bool fullscreen);

	void render();
	void clear();

private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;

};