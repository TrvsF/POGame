/*----------
	wall class
	wall game object that collides with the player and other
	game objects

	a. travis 7th jan
----------*/
#ifndef _WALL_H
#define _WALL_H

#include "game_entity.h"
#include "texture.h"
#include "physics.h"

class wall : public game_entity
{
	private:

	public:
		wall(Vector2 position);
		~wall();

		void update();
		void render();
};
#endif