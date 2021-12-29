#pragma once
#include "math_helper.h"
/*----------
	game entity class
	main class that all game objects inherit from

	a. travis 22nd dec
----------*/
class game_entity
{
	private:
		BoundingBox m_bb;
		Vector2 m_pos;

		float m_rotation;
		float m_velocity;

		bool m_player;
		bool m_active;

		game_entity* m_parent;

	public:
		enum SPACE 
		{
			local = 0,
			world = 1
		};

		game_entity(Vector2 pos = VEC2_ZERO);
		~game_entity();

		void pos(Vector2 pos);
		Vector2 pos(SPACE space);

		void bb(float x, float y, int width, int height);
		void bb(BoundingBox bb);
		BoundingBox bb(SPACE space);

		void rotation(float rotation);
		float rotation(SPACE space);

		void active(bool active);
		bool active();

		void velocity(float vel);
		float velocity();

		void playerControlled(bool isPlayer);
		bool playerControlled();

		void parent(game_entity* parent);
		game_entity* parent();

		void translate(Vector2 vec);

		virtual void update();
		virtual void render();
};