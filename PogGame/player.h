#pragma once
#include "game_entity.h"
#include "inputs.h"
#include <iostream>
/*----------
	player class
	inherits from game entity
	is the game object that the player controls during the game

	a. travis 23rd dec
----------*/
class player : public game_entity
{
	private:	
		const int BOOST_COOLDOWN = 210; // ammount of frames until can boost again
		const float MAX_VEL = 2.0f; // max normal velocity without boost
		const float MAX_VEL_BOOST = 6.5f; // max boosted velocity
		const float BOOST_MUL[3] = {1.7f, 2.2f, 1.2f}; // how fast you are boosted dependent of if you're turning
		// ^ lower values mean that you have to spam space more for it to work

		inputs* m_inputs;

		float m_tickVelocity;

		bool m_hasBoosted;
		bool m_canBoost;
		int m_boostCooldownCount;
		int m_boostIndex;

		void playerInput();
		void checkBoostCooldown();

		void turnRight();
		void turnLeft();
		void moveForward();
		void moveBackward();
		void boost();

		float calcVelocity();

	public:
		player(Vector2 pos);

		Vector2 getMovement();

		void cancelBoost();

		void lateUpdate();
		void update();
		void render();
};