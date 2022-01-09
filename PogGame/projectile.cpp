#include "projectile.h"

projectile::projectile(float angle, Vector2 position)
{
	setTexture("proj.png");
	pos(position);
	rotation(angle);
	
	movementVec = Vector2(0, -1.0f);
	movementVec = RotateVector(movementVec, rotation(world));
}

projectile::~projectile()
{

}

void projectile::update()
{
	translate(movementVec);
}

void projectile::render()
{
	renderTexture();
}
