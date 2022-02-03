#include "projectile.h"

projectile::projectile(float angle, float speed, float spread, float damage, Vector2 position, game_entity* parent)
{
	type(EntityType::PROJECTILE);

	// set position and rotation
	pos(position);
	rotation(angle + randomFloat(-spread, spread));
	
	// set movement vector
	m_movementVec = Vector2(0, -speed);
	m_movementVec = RotateVector(m_movementVec, rotation());

	m_parent = parent;

	setTexture("proj.png");

	m_damage = damage;

	m_counter = 0;
	m_shouldRender = true;

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
		m_shouldRender = false;
	}

	m_counter++;
}

void projectile::render()
{
	if (!m_shouldRender)
		return;

	renderTexture();
}
