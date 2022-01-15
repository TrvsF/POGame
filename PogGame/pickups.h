#ifndef _PICKUPS_H
#define _PICKUPS_H

#include "game_entity.h"

class pickups : public game_entity
{
	private:


	public:
		pickups(Vector2 position);
		virtual ~pickups();

		void render();
		void update();
};
#endif