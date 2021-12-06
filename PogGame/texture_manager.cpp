#include "texture_manager.h"

SDL_Texture* texture_manager::loadTexture(const char* filePath, SDL_Renderer* renderer)
{
	SDL_Surface* tempSurface = IMG_Load(filePath);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	
	SDL_FreeSurface(tempSurface);

	return texture;
}
