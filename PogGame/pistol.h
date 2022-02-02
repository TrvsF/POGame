/*----------
	pistol class

	a. travis 2nd feb
----------*/
#ifndef _PISTOL_H
#define _PISTOL_H

#include "pickup.h"
#include "physics.h"

class pistol : public pickup
{
	private:

	public:
		pistol(Vector2 position);
		virtual ~pistol();

		void onPickup(game_entity* pickeruper);
		void shoot();

		void update();
		void render();
};
#endif