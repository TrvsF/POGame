#include "projectile.h"

projectile::projectile(float rotation, Vector2 position)
{
	setTexture("proj.png");
	pos(position);
	
	movementVec = Vector2(0, -1.0f);
	RotateVector(movementVec, rotation);
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
