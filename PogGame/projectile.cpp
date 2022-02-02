#include "projectile.h"

projectile::projectile(float angle, float speed, Vector2 position, game_entity* parent)
{
	type(EntityType::PROJECTILE);

	pos(position);
	rotation(angle + randomFloat(-3.0f, 3.0f));
	
	m_movementVec = Vector2(0, -speed);
	m_movementVec = RotateVector(m_movementVec, rotation());

	m_parent = parent;

	setTexture("proj.png");

	m_damage = 25;

	physics::INSTANCE()->addEntity(this);
}

projectile::~projectile()
{

}

void projectile::update()
{
	translate(m_movementVec);
	game_entity* entity = physics::INSTANCE()->getWhatCollidesWithBB(bb(), this, m_parent);
	if (entity != NULL)
	{
		entity->takeDamage(m_damage);
		m_damage = 0;
	}
}

void projectile::render()
{
	renderTexture();
}
