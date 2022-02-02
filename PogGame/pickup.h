/*----------
	pickup class
	pickup object for all pickups to inherit from

	a. travis 2nd feb
----------*/
#ifndef _PICKUP_H
#define _PICKUP_H

#include "game_entity.h"

class pickup : public game_entity 
{
	private: 


	public:
		pickup(Vector2 pos = VEC2_ZERO);
		virtual ~pickup();

		virtual void onPickup(game_entity* pickeruper);
		virtual void onDrop();

		virtual void shoot();

		virtual void update();
		virtual void render();
};

#endif