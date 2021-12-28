#pragma once
#include "game_entity.h"
#include "texture.h"
#include "inputs.h"
/*----------
	player class
	inherits from game entity
	is the game object that the player controls during the game

	a. travis 23rd dec
----------*/
class player : public game_entity
{
	private:	
		const int BOOST_COOLDOWN = 144; // 1 second from last boost until can do again
		const float MAX_VEL = 2.0f;
		const float MAX_VEL_BOOST = 6.5f;
		const float BOOST_MUL[3] = {1.9f, 2.2f, 1.2f};

		inputs* m_inputs;
		texture* m_texture;

		float m_tickVelocity;

		bool m_hasBoosted;
		bool m_canBoost;
		int m_boostCooldownCount;
		int m_boostIndex;

		void playerInput();
		void checkBoostCooldown();

		float calcVelocity();

	public:
		player(Vector2 pos);

		void turnRight();
		void turnLeft();
		void moveForward();
		void moveBackward();
		void boost();

		void update();
		void render();
};