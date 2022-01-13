#pragma once
#include "game_entity.h"

class pickups : public game_entity
{
	private:


	public:
		pickups(Vector2 position);
		~pickups();

		void render();
		void update();
};
