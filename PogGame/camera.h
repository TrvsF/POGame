/*----------
	camera class
	tracks a game entity

	a. travis 23rd dec
----------*/
#ifndef _CAMERA_H
#define _CAMERA_H

#include "math_helper.h"
#include "graphics.h"

class camera
{
	private:
		static camera* s_instance;

		BoundingBox m_bb;
		Vector2 m_offset;

		void debugRenderBB();

	public:
		static camera* INSTANCE();

		camera();
		~camera();

		void offset(Vector2 o);
		Vector2 offset();

		void setBB(int x, int y, int width, int height);
		void translate(Vector2 pos);

		void update();
		void render();
};

#endif