#include "texture_helper.h"

// load texture from path
SDL_Texture* texture_helper::loadTexture(std::string path)
{
	SDL_Renderer* renderer = graphics::INSTANCE()->renderer();

	SDL_Surface* tempSurface = IMG_Load(path.c_str());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);

	if (tempSurface == NULL || texture == NULL)
	{
		printf("error initialising texture from path %s\n", path.c_str());
	}

	// surface no longer needed
	SDL_FreeSurface(tempSurface);

	return texture;
}

SDL_Surface * texture_helper::loadSurface(std::string path)
{
	return IMG_Load(path.c_str());
}

SDL_Texture * texture_helper::loadText(TTF_Font* font, std::string text, SDL_Color colour)
{
	SDL_Renderer* renderer = graphics::INSTANCE()->renderer();

	SDL_Surface* tempSurface = TTF_RenderText_Solid(font, text.c_str(), colour);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);

	if (tempSurface == NULL || texture == NULL)
	{
		printf("error initialising text '%s'\n", text.c_str());
	}

	SDL_FreeSurface(tempSurface);

	return texture;

}
