#pragma once
#include "player.h"
#include "math_helper.h"
#include "game_entity.h"
#include <list>
/*----------
	physics manager class
	handles all physics between game objects

	a. travis 29th dec
----------*/
class physics
{
	private:
		static physics* s_instance;

		std::list<game_entity*> m_gameEntities;
		std::list<game_entity*>::iterator m_gameEntitiesI;

		std::list<player*> m_playerEntities;
		std::list<player*>::iterator m_playerEntitiesI;

		physics();
		~physics();

	public:
		static physics* INSTANCE();

		void addEntity(game_entity* entity);
		void addPlayer(player* player);

		bool isGoingToCollide(BoundingBox playerBB);
};