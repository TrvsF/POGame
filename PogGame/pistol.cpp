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

	m_projCounter = 0;
	m_tickCounter = 0;

	physics::INSTANCE()->addPickup(this);
}

pistol::~pistol()
{
}

void pistol::shoot(float angle)
{
	if (m_projCounter > 20)
		m_projCounter = 1;

	m_projectiles[m_projCounter] = new projectile(angle, 7.0f, centerPos(), m_parent);

	m_projCounter++;
}

void pistol::update()
{
	m_tickCounter++;

	for (int i = 0; i < 20; i++)
	{
		if (m_projectiles[i] == nullptr)
			continue;

		m_projectiles[i]->update();
	}
}

void pistol::render()
{
	renderTexture();
	
	for (int i = 0; i < 20; i++)
	{
		if (m_projectiles[i] == nullptr)
			continue;

		m_projectiles[i]->render();
	}
}
