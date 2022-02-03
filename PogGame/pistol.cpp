#include "pistol.h"

void pistol::onPickup(game_entity* pickeruper)
{
	pos(pickeruper->pos());
	setTexture("arms.png");

	m_parent = pickeruper;

	physics::INSTANCE()->removePickup(this);
}

void pistol::onDrop()
{
	setTexture("pickup_pistol.png");
	rotation(0);
	m_parent = NULL;
	physics::INSTANCE()->addPickup(this);
}

pistol::pistol(Vector2 position)
{
	pos(position);
	setTexture("pickup_pistol.png");

	m_tickCounter = 0;

	physics::INSTANCE()->addPickup(this);
}

pistol::~pistol()
{
}

void pistol::shoot(float angle)
{
	if (m_tickCounter < SHOT_COOLDOWN_TICKS)
		return;

	levels::INSTANCE()->addProjectile(new projectile(angle, SPEED, m_parent->velocity() * INACCURACY + 1.0f, DAMAGE, centerPos(), m_parent));

	m_tickCounter = 0;
}

void pistol::update()
{
	m_tickCounter++;
}

void pistol::render()
{
	renderTexture();
}
