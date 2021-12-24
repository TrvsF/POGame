#pragma once
#include "SDL_image.h"
#include "graphics.h"
#include <iostream>
/*----------
	texture helper class
	class with static methods to aid in loading textures

	a. travis 21st dec
----------*/
class texture_helper
{

	public:
		static SDL_Texture* loadTexture(std::string path);

};

