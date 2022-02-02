/*----------
	physics manager class
	handles all physics between game objects

	a. travis 29th dec
----------*/
#ifndef _PHYSICS_H
#define _PHYSICS_H

#include "math_helper.h"
#include "game_entity.h"
#include "pickup.h"
#include <list>

class physics
{
	private:
		static physics* s_instance;

		std::list<game_entity*> m_gameEntities;
		std::list<pickup*> m_pickups;

		physics();
		~physics();

	public:
		static physics* INSTANCE();

		void addPickup(pickup* pickup);
		void removePickup(pickup* pickup);

		void addEntity(game_entity* entity);
		void removeEntity(game_entity* entity);
		void translateEntitiesNotPlayer(Vector2 vector);

		bool isAnythingNotSelfGoingToCollideWithBB(BoundingBox objectBB, game_entity* self);

		pickup* getPickupsWithBB(BoundingBox objectBB);
		game_entity* getWhatCollidesWithBB(BoundingBox objectBB, game_entity* self, game_entity* parent);
};
#endif