#include "wall.h"

wall::wall(Vector2 position)
{
	pos(position);
	setTexture("brickl.png");

	physics::INSTANCE()->addEntity(this);
}

wall::~wall()
{

}

void wall::update()
{
	// TODO : ADD SOME PHYSICS
}

void wall::render()
{
	drawDebugBB();
	renderTexture();
}