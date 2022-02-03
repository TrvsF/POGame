/*----------
	shotgun class

	a. travis 3rd feb
----------*/
#ifndef _SHOTGUN_H
#define _SHOTGUN_H

#include "pickup.h"
#include "physics.h"
#include "projectile.h"
#include "levels.h"

class shotgun : public pickup
{
	private:
		const int SHOT_COOLDOWN_TICKS = 65;
		const int RELOAD_TICKS = 20;
		const int MAG_SIZE = 7;

		const float SPEED = 15.0f;
		const float INACCURACY = 5.5f;
		const float DAMAGE = 15.0f;

		long m_tickCounter;

		game_entity* m_parent;

	public:
		shotgun(Vector2 position);
		virtual ~shotgun();

		void onPickup(game_entity* pickeruper);
		void shoot(float angle);

		void update();
		void render();
};
#endif