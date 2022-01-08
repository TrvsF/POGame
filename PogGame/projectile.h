#pragma once
#include "game_entity.h"

class projectile : public game_entity
{
	private:
		Vector2 movementVec;

	public:
		projectile(float rotation, Vector2 position);
		~projectile();

		void update();
		void render();
};