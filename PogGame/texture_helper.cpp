#include "texture_helper.h"

SDL_Texture* texture_helper::loadTexture(std::string path)
{
	SDL_Renderer* renderer = graphics::INSTANCE()->renderer();
	SDL_Surface* tempSurface = IMG_Load(path.c_str());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);

	if (tempSurface == NULL || texture == NULL)
	{
		printf("error initialising texture from path %s\n", path);
	}

	SDL_FreeSurface(tempSurface);

	return texture;
}