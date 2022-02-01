#include "projectile.h"

projectile::projectile(float angle, float speed, Vector2 position)
{
	type(EntityType::PROJECTILE);

	pos(position);
	rotation(angle + randomFloat(-3.0f, 3.0f));
	
	movementVec = Vector2(0, -speed);
	movementVec = RotateVector(movementVec, rotation());

	setTexture("proj.png");

	physics::INSTANCE()->addEntity(this);
}

projectile::~projectile()
{

}

void projectile::update()
{
	translate(movementVec);
	game_entity* entity = physics::INSTANCE()->getWhatCollidesWithBB(bb(), this);
	if (entity != NULL)
	{
		entity->takeDamage(50);
	}
}

void projectile::render()
{
	renderTexture();
}
