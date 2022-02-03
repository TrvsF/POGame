#include "pistol.h"

void pistol::onPickup(game_entity* pickeruper)
{
	pos(pickeruper->pos());
	setTexture("arms.png");

	m_parent = pickeruper;

	physics::INSTANCE()->removePickup(this);
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
	levels::INSTANCE()->addProjectile(new projectile(angle, 7.0f, centerPos(), m_parent));
}

void pistol::update()
{
	m_tickCounter++;
}

void pistol::render()
{
	renderTexture();
}
