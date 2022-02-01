#include "wall.h"

wall::wall(Vector2 position)
{
	pos(position);
	setTexture("brickl.png");

	type(EntityType::GEOMETRY);

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
	// drawDebugBB();
	renderTexture();
}