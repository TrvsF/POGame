#pragma once
#include "game_entity.h"

class projectile : public game_entity
{
	private:
		Vector2 movementVec;

	public:
		projectile(float angle, float speed, Vector2 position);
		~projectile();

		void update();
		void render();
};