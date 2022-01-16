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

class enemy : public game_entity
{
	private:
		enum e_aiStates { wandering, attacking, chasing, dead };

		e_aiStates currentState;

		int velocity;

		void calcVelocity();
		void calcRotation();

	public:
		enemy(Vector2 position);
		virtual ~enemy();

		void update();
		void render();
};

#endif