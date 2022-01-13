#include "camera.h"

camera::camera()
{
}

camera::~camera()
{
}

void camera::debugRenderBB()
{
	SDL_Rect rect;
	rect.x = (int)m_bb.left;
	rect.y = (int)m_bb.top;
	rect.w = (int)m_bb.right - (int)m_bb.left;
	rect.h = (int)m_bb.bottom - (int)m_bb.top;

	SDL_SetRenderDrawColor(graphics::INSTANCE()->renderer(), 255, 0, 0, 255);
	SDL_RenderDrawRect(graphics::INSTANCE()->renderer(), &rect);

	SDL_SetRenderDrawColor(graphics::INSTANCE()->renderer(), 255, 255, 255, 255);
}

void camera::bb(int x, int y, int width, int height)
{
	m_bb = BoundingBox((float)x, (float)y, (float)y - height, (float)x - width);
	m_bb += Vector2(width / 2.0f, height / 2.0f);
}

BoundingBox camera::bb()
{
	return m_bb;
}

void camera::translate(Vector2 pos)
{
	m_bb += pos;
}

void camera::update()
{
	if (m_bb.isOutOfBounds(1024, 768))
	{
		
	}
}

void camera::render()
{
	debugRenderBB();
}
