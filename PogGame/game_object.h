#include "common.h"
#include "game.h"
#pragma once

class game_object
{

public:
	game_object(const char* texturesheet, SDL_Renderer* renderer, int x, int y);
	~game_object();

	void update();
	void render();

	int xPos;
	int yPos;

private:
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* localRenderer;

};

