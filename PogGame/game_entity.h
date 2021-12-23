
#pragma once
#include "math_helper.h"

class game_entity
{
	public:
		enum SPACE {
			local = 0,
			world = 1
		};

		game_entity(Vector2 pos = VEC2_ZERO);
		~game_entity();

		void pos(Vector2 pos);
		Vector2 pos(SPACE space);

		void rotation(float rotation);
		float rotation(SPACE space);

		void active(bool active);
		bool active();

		void parent(game_entity* parent);
		game_entity* parent();

		virtual void update();
		virtual void render();

	private:
		Vector2 m_pos;
		float m_rotation;

		bool m_active;
		game_entity* m_parent;

};