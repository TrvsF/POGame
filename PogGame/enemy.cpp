#include "enemy.h"

Vector2 enemy::getMovementVec()
{
	float calcVel = calcVelocity();
	velocity(calcVel);
	Vector2 movement = Vector2(0, calcVel);
	return RotateVector(movement, rotation());
}

float enemy::calcVelocity()
{
	float vel = velocity() + m_tickVelocity;
	float velMag = abs(vel);

	// if enemy is not moving
	if (m_tickVelocity == 0)
	{
		// if vel is close to 0 set to 0
		if (velMag < 0.05f)
		{
			return 0;
		}
		return vel > 0 ? vel - 0.05f : vel + 0.05f;
	}

	// clamp vel to max vel
	if (velMag > MAX_VELOCITY)
	{
		return vel > 0 ? MAX_VELOCITY : -MAX_VELOCITY;
	}

	// else return the newly calculated velocity
	return vel;
}

void enemy::knockback(float kb)
{
	m_tickVelocity = kb;
}

void enemy::doMovement()
{
	Vector2 movementVec = getMovementVec();

	BoundingBox nextFrameBB = bb() + movementVec;

	if (physics::INSTANCE()->isAnythingNotSelfGoingToCollideWithBB(nextFrameBB, this))
	{
		Vector2 xVec = Vector2(movementVec.x, 0);
		Vector2 yVec = Vector2(0, movementVec.y);

		BoundingBox xbb = bb() + xVec;
		BoundingBox ybb = bb() + yVec;

		if (!physics::INSTANCE()->isAnythingNotSelfGoingToCollideWithBB(xbb, this))
		{
			translate(xVec);
		}

		if (!physics::INSTANCE()->isAnythingNotSelfGoingToCollideWithBB(ybb, this))
		{
			translate(yVec);
		}

		return;
	}
	else
	{
		translate(movementVec);
	}
}

void enemy::doDeath()
{
	m_isAlive = false;
	physics::INSTANCE()->removeEntity(this);
}

enemy::enemy(Vector2 position)
{
	pos(position);
	health(50);
	m_isAlive = true;
	m_tickVelocity = 0;

	setTexture("enemy.png");
	type(EntityType::AI);

	currentState = wandering;

	physics::INSTANCE()->addEntity(this);
}

enemy::~enemy()
{
}

void enemy::takeDamage(int hp, float kb, float r)
{
	knockback(kb);
	health(health() - hp);

	rotation(r - 180.0f);

	if (health() <= 0)
	{
		doDeath();
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

	doMovement();
	
	m_tickVelocity = 0;
}

void enemy::render()
{
	if (!m_isAlive)
		return;

	renderTexture();
}
