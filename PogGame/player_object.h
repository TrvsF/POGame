#include "common.h"
#include "game.h"
#pragma once

class player_object
{

	public:
		player_object(const char* texturesheet, SDL_Renderer* renderer, int x, int y);
		~player_object();

		void update();
		void render();
		void handleTurning();
		void handleMovement();

		int movementVect[4];

	private:
		void moveToPoint();

		SDL_Texture* objTexture;
		SDL_Rect srcRect, destRect;
		SDL_Renderer* localRenderer;

		float xPos;
		float yPos;

		float angle;
		float moveVelocity;

};

