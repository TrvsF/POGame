#pragma once
#include "game_entity.h"
#include "texture.h"
#include "physics.h"

class wall : public game_entity
{
	private:

	public:
		wall(Vector2 position);
		~wall();

		void update();
		void render();
};