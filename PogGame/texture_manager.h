#pragma once
#include "SDL_image.h"

class texture_manager
{

	public:
		static SDL_Texture* loadTexture(const char* fileName, SDL_Renderer* renderer);

};

