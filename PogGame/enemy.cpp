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

	setTexture("enemy.png");

	currentState = wandering;

	physics::INSTANCE()->addEntity(this);
}

enemy::~enemy()
{
}

void enemy::update()
{
	switch (currentState)
	{
		case wandering:
			// 1 in 100 chance
			if (randomFloat(0, 100.0f) > 99.0f)
			{
				rotation(rotation() + randomFloat(0, 60.0f));
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
	renderTexture();
}
