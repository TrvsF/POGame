#include "wall.h"

wall::wall(Vector2 position)
{
	pos(position);
	setTexture("brickl.png");
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
	renderTexture();
}