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

	m_damage = 5;
	m_counter = 0;

	physics::INSTANCE()->addEntity(this);
}

projectile::~projectile()
{

}

bool projectile::shouldDie()
{
	return m_counter >= ALIVE_TIME;
}

void projectile::update()
{
	translate(m_movementVec);
	game_entity* entity = physics::INSTANCE()->getWhatCollidesWithBB(bb(), this, m_parent);
	if (entity != NULL)
	{
		entity->takeDamage(m_damage, 5.0f, rotation());
		m_damage = 0;
	}
	m_counter++;
}

void projectile::render()
{
	renderTexture();
}
