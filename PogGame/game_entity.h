/*----------
	game entity class
	main class that all game objects inherit from

	a. travis 22nd dec
----------*/
#ifndef _GAME_ENT_H
#define _GAME_ENT_H

#include "math_helper.h"
#include "texture.h"

class game_entity
{
	private:
		BoundingBox m_bb;
		Vector2 m_pos;

		texture* m_texture;

		float m_rotation;
		float m_velocity;

		bool m_active;

		game_entity* m_parent;

	public:
		game_entity(Vector2 pos = VEC2_ZERO);
		virtual ~game_entity();

		void pos(Vector2 pos);
		Vector2 centerPos();
		Vector2 pos();

		void bb(float x, float y, int width, int height);
		void bb(BoundingBox bb);
		BoundingBox bb();

		void rotation(float rotation);
		float rotation();

		void active(bool active);
		bool active();

		void velocity(float vel);
		float velocity();

		void parent(game_entity* parent);
		game_entity* parent();

		void setTexture(std::string path);
		void renderTexture();

		void translate(Vector2 vec);

		void setBB();
		void drawDebugBB();

		virtual void update();
		virtual void render();
};
#endif