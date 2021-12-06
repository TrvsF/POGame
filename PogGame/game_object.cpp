#include "game_object.h"
#include "texture_manager.h"

game_object::game_object(const char* texturesheet, SDL_Renderer* renderer, int x, int y)
{
	localRenderer = renderer;
	objTexture = texture_manager::loadTexture(texturesheet, renderer);

	xPos = x;
	yPos = y;
}

void game_object::update()
{
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h * 1;
	destRect.w = srcRect.w * 1;
	destRect.x = xPos;
	destRect.y = yPos;
}

void game_object::render()
{
	SDL_RenderCopy(localRenderer, objTexture, &srcRect, &destRect);
}
