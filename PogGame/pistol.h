/*----------
	pistol class

	a. travis 2nd feb
----------*/
#ifndef _PISTOL_H
#define _PISTOL_H

#include "pickup.h"
#include "physics.h"
#include "projectile.h"

class pistol : public pickup
{
	private:
		const int SHOT_COOLDOWN_TICKS = 20;
		const int RELOAD_TICKS = 15;
		const int MAG_SIZE = 13;

		int m_tickCounter;
		int m_projCounter;

		projectile* m_projectiles[20];
		game_entity* m_parent;

	public:
		pistol(Vector2 position);
		virtual ~pistol();

		void onPickup(game_entity* pickeruper);
		void shoot(float angle);

		void update();
		void render();
};
#endif