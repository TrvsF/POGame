/*----------
	player class
	inherits from game entity
	is the game object that the player controls during the game

	a. travis 23rd dec
----------*/
#ifndef _PLAYER_H
#define _PLAYER_H

#include "game_entity.h"
#include "inputs.h"
#include "projectile.h"
#include "physics.h"
#include "camera.h"
#include <iostream>

class player : public game_entity
{
	private:	
		const int BOOST_COOLDOWN = 210; // ammount of frames until can boost again
		const float MAX_VEL = 2.6f; // max normal velocity without boost
		const float MAX_VEL_BOOST = 7.5f; // max boosted velocity
		const float BOOST_MUL[3] = {2.1f, 2.2f, 1.2f}; // how fast you are boosted dependent of if you're turning
		// ^ lower values mean that you have to spam space more for it to work

		projectile* projectiles[100];

		inputs* m_inputs;

		camera* m_camera;

		texture* m_xHairTex;
		texture* m_xHairTexRed;

		float m_tickVelocity;

		int m_boostCooldownCount;
		int m_boostIndex;
		int m_projCount;

		bool m_hasBoosted;
		bool m_canBoost;

		// player handling
		Vector2 getMovement();
		float calcVelocity();

		void playerInput();
		void checkBoostCooldown();
		void handleQuarterSteps();
		void cancelBoost();

		// movement methods
		void turnRight();
		void turnLeft();
		void moveForward();
		void moveBackward();
		void boost();

		// camera related methods
		bool shouldMoveObjects(Vector2 movementVe);

		void movePlayer(Vector2 movementVec);

		// mouse/shooting methods
		void shoot();
		void renderXhair();
		bool canShoot();

	public:
		player(Vector2 pos);
		virtual ~player();

		void update();
		void render();
};
#endif