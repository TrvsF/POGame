#pragma once
#include "SDL_image.h"
#include <iostream>

class texture_helper
{

	public:
		static SDL_Texture* loadTexture(const char* fileName, SDL_Renderer* renderer);

};

