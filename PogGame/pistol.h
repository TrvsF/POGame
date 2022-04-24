/*----------
	pistol class

	a. travis 2nd feb
----------*/
#ifndef _PISTOL_H
#define _PISTOL_H

#include "physics.h"
#include "pickup.h"
#include "levels.h"

class pistol : public pickup
{
	private:
		const int SHOT_COOLDOWN_TICKS = 35;
		const int RELOAD_TICKS = 15;
		const int MAG_SIZE = 13;

		const float SPEED = 19.0f;
		const float INACCURACY = 1.75f;
		const float DAMAGE = 20.0f;

		long m_tickCounter;

		game_entity* m_parent;

		void onDrop();

	public:
		pistol(Vector2 position);
		virtual ~pistol();

		void onPickup(game_entity* pickeruper);
		void shoot(float angle);

		void update();
		void render();
};
#endif