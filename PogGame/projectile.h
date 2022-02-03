/*----------
	projectile class
	projectile object shot from guns 

	a. travis 8th jan
----------*/
#ifndef _PROJ_H
#define _PROJ_H

#include "game_entity.h"
#include "physics.h"

class projectile : public game_entity
{
	private:
		const int ALIVE_TIME = 500;

		game_entity* m_parent;

		Vector2 m_movementVec;

		int m_damage;
		int m_counter;

	public:
		projectile(float angle, float speed, Vector2 position, game_entity* parent);
		virtual ~projectile();

		bool shouldDie();

		void update();
		void render();
};
#endif