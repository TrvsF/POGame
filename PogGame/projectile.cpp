#include "projectile.h"

projectile::projectile(float angle, float speed, Vector2 position)
{
	setTexture("proj.png");
	pos(position);
	rotation(angle + randomFloat(-5.0f, 5.0f));
	
	movementVec = Vector2(0, -speed);
	movementVec = RotateVector(movementVec, rotation());

	physics::INSTANCE()->addEntity(this);
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
