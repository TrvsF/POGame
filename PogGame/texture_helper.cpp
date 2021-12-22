#include "texture_helper.h"

SDL_Texture* texture_helper::loadTexture(const char* filePath, SDL_Renderer* renderer)
{
	SDL_Surface* tempSurface = IMG_Load(filePath);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);

	if (tempSurface == NULL || texture == NULL)
	{
		printf("error initialising texture from path %s\n", filePath);
	}

	SDL_FreeSurface(tempSurface);

	return texture;
}
