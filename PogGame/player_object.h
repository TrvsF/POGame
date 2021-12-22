#pragma once
#include <iostream>
#include "texture_helper.h"

class player_object
{

	public:
		player_object(const char* texturesheet, SDL_Renderer* renderer, int x, int y);
		~player_object();

		void update();
		void render();
		void handleTurning();
		void handleMovement();

		int movementVector[4];

	private:
		const float MAX_VEL = 0.03f;
		const float MOVEMENT_MOMENTUM = 0.00003f;
		const float TURNING_MOMENTUM = 0.00055f;

		void moveToPoint();

		SDL_Texture* m_playerTexture;
		SDL_Rect m_srcRect, m_destRect;
		SDL_Renderer* m_renderer;

		float m_posX;
		float m_posY;

		float m_angle;
		float m_velocity;

};

