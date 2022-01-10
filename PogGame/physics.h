/*----------
	physics manager class
	handles all physics between game objects

	a. travis 29th dec
----------*/
#ifndef _PHYSICS_H
#define _PHYSICS_H

#include "math_helper.h"
#include "game_entity.h"
#include <list>

class physics
{
	private:
		static physics* s_instance;

		std::list<game_entity*> m_gameEntities;
		std::list<game_entity*>::iterator m_gameEntitiesI;

		physics();
		~physics();

	public:
		static physics* INSTANCE();

		void addEntity(game_entity* entity);

		bool isGoingToCollide(BoundingBox playerBB);
};
#endif