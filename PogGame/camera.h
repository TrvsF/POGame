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
		BoundingBox m_bb;

		void debugRenderBB();

	public:
		static camera* INSTANCE();

		camera();
		~camera();

		void bb(int x, int y, int width, int height);
		BoundingBox bb();

		void translate(Vector2 pos);

		void update();
		void render();
};

#endif