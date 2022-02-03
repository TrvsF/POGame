#include "shotgun.h"

void shotgun::onDrop()
{
	setTexture("pickup_shotgun.png");
	rotation(0);
	m_parent = NULL;
	physics::INSTANCE()->addPickup(this);
}

shotgun::shotgun(Vector2 position)
{
	pos(position);
	setTexture("pickup_shotgun.png");

	m_tickCounter = 0;

	physics::INSTANCE()->addPickup(this);
}

shotgun::~shotgun()
{
}

void shotgun::onPickup(game_entity* pickeruper)
{
	pos(pickeruper->pos());
	setTexture("shotgun.png");

	m_parent = pickeruper;

	physics::INSTANCE()->removePickup(this);
}

void shotgun::shoot(float angle)
{
	if (m_tickCounter < SHOT_COOLDOWN_TICKS)
		return;

	levels::INSTANCE()->addProjectile(new projectile(angle, SPEED, (m_parent->velocity() + 1.0f) * INACCURACY, DAMAGE, centerPos(), m_parent));
	levels::INSTANCE()->addProjectile(new projectile(angle, SPEED, (m_parent->velocity() + 1.0f) * INACCURACY, DAMAGE, centerPos(), m_parent));
	levels::INSTANCE()->addProjectile(new projectile(angle, SPEED, (m_parent->velocity() + 1.0f) * INACCURACY, DAMAGE, centerPos(), m_parent));
	levels::INSTANCE()->addProjectile(new projectile(angle, SPEED, (m_parent->velocity() + 1.0f) * INACCURACY, DAMAGE, centerPos(), m_parent));
	levels::INSTANCE()->addProjectile(new projectile(angle, SPEED, (m_parent->velocity() + 1.0f) * INACCURACY, DAMAGE, centerPos(), m_parent));
	levels::INSTANCE()->addProjectile(new projectile(angle, SPEED, (m_parent->velocity() + 1.0f) * INACCURACY, DAMAGE, centerPos(), m_parent));

	m_tickCounter = 0;
}

void shotgun::update()
{
	m_tickCounter++;
}

void shotgun::render()
{
	renderTexture();
}
