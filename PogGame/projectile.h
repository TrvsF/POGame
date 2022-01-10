/*----------
	projectile class
	projectile object shot from guns 

	a. travis & kai 8th jan
----------*/
#ifndef _PROJ_H
#define _PROJ_H

#include "game_entity.h"

class projectile : public game_entity
{
	private:
		Vector2 movementVec;

	public:
		projectile(float angle, float speed, Vector2 position);
		~projectile();

		void update();
		void render();
};
#endif