#include "enemy.h"

void enemy::calcVelocity()
{
}

void enemy::calcRotation()
{
}

enemy::enemy(Vector2 position)
{
	pos(position);
	health(50);
	m_isAlive = true;

	setTexture("enemy.png");
	type(EntityType::AI);

	currentState = wandering;

	physics::INSTANCE()->addEntity(this);
}

enemy::~enemy()
{
}

void enemy::takeDamage(int hp)
{
	health(health() - hp);

	if (health() <= 0)
	{
		m_isAlive = false;
		physics::INSTANCE()->removeEntity(this);
	}
}

void enemy::update()
{
	if (!m_isAlive)
		return;

	switch (currentState)
	{
		case wandering:
			// 1 in 100 chance
			if (randomFloat(0, 100.0f) > 99.0f)
			{
				rotation(rotation() + randomFloat(-60.0f, 60.0f));
			}
			break;
		case attacking:
			break;
		case chasing:
			break;
		case dead:
			break;
	}
	
}

void enemy::render()
{
	if (!m_isAlive)
		return;

	renderTexture();
}
