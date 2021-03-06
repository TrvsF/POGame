/*----------
	eneny class
	inherits from game entity
	default class for enemies

	a. travis 23rd dec
----------*/
#ifndef _ENEMY_H
#define _ENEMY_H

#include "game_entity.h"
#include "physics.h"
#include <iostream>

class enemy : public game_entity
{
	private:
		const float MAX_VELOCITY = 2.5f;

		enum e_aiState { wandering, attacking, chasing, dead };

		e_aiState m_currentState;

		bool m_isAlive;

		float m_tickVelocity;
		float m_kbRotation;

		Vector2 getMovementVec();
		float calcVelocity();
		void knockback(float kb);
		void doMovement();

		void doDeath();

	public:
		enemy(Vector2 position);
		virtual ~enemy();

		void takeDamage(int hp, float kb, float r);

		void update();
		void render();
};

#endif