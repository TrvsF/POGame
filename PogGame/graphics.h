#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "texture.h"
#include "player_object.h"

class graphics
{
public:
	static graphics* INSTANCE();

	graphics();
	~graphics();

	bool init(const char* title, int xPos, int yPos, int width, int hieght, bool fullscreen);
	SDL_Renderer* renderer();

	void render();
	void clear();

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	static graphics* s_instance;

};