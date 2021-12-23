#pragma once
#include "SDL_image.h"
#include "graphics.h"
#include <iostream>

class texture_helper
{

	public:
		static SDL_Texture* loadTexture(std::string path);

};

