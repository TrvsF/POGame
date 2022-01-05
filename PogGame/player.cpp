#include "player.h"

player::player(Vector2 position)
{
	pos(position);
	playerControlled(true);

	m_inputs = inputs::INSTANCE();

	setTexture("character.png");

	m_tickVelocity = 0;

	m_boostIndex = 0;
	m_canBoost = true;
	m_hasBoosted = false;
	m_boostCooldownCount = 0;
}

void player::playerInput()
{
	if (m_inputs->keyDown(SDL_SCANCODE_W))
	{
		moveForward();
	}
	if (m_inputs->keyDown(SDL_SCANCODE_S))
	{
		moveBackward();
	}
	if (m_inputs->keyDown(SDL_SCANCODE_D))
	{
		turnRight();
	}
	if (m_inputs->keyDown(SDL_SCANCODE_A))
	{
		turnLeft();
	}
	if (m_inputs->keyPressed(SDL_SCANCODE_SPACE))
	{
		boost();
	}
}

void player::checkBoostCooldown()
{
	if (!m_canBoost)
	{
		m_boostCooldownCount++;
		if (m_boostCooldownCount > BOOST_COOLDOWN)
		{
			m_canBoost = true;
			m_boostCooldownCount = 0;
		}
	}
}

// calculate new player velocity given some ammount to add
float player::calcVelocity()
{
	// get what the velocity would be
	float vel = velocity() + m_tickVelocity;
	float velMag = abs(vel);
	// if is going too fast even for boost clamp vel
	if (velMag > MAX_VEL_BOOST)
	{
		vel = vel > 0 ? MAX_VEL_BOOST : -MAX_VEL_BOOST;
	}
	// if no velocity is being added then either remain at rest
	// or start to slow the character down
	if (m_tickVelocity == 0)
	{
		// if vel is close to 0 set to 0
		if (velMag < 0.05f)
		{
			return 0;
		}
		// else return the player's velocity but slowed down
		return vel > 0 ? vel - 0.05f : vel + 0.05f;
	}
	// if calculated velocity is over the max then return max veloicty (- or +)
	if (velMag > MAX_VEL && !m_hasBoosted)
	{
		return vel > 0 ? MAX_VEL : -MAX_VEL;
	}
	// else return the newly calculated velocity
	return vel;
}

void player::turnRight()
{
	m_boostIndex++;
	rotation(rotation(world) + 3.5f);
}

void player::turnLeft()
{
	m_boostIndex++;
	rotation(rotation(world) - 3.5f);
}

void player::moveForward()
{
	if (velocity() >= -2)
		m_tickVelocity -= 2;
}

void player::moveBackward()
{
	if (velocity() <= 2)
		m_tickVelocity += 2;
}

void player::boost()
{
	if (m_canBoost)
	{
		velocity(velocity() * BOOST_MUL[m_boostIndex]);
		m_hasBoosted = true;
	}

	if (m_inputs->keyDown(SDL_SCANCODE_W) || m_inputs->keyDown(SDL_SCANCODE_S))
		m_canBoost = false;
}

Vector2 player::getMovement()
{
	velocity(calcVelocity());
	Vector2 movement = Vector2(0, calcVelocity());
	return RotateVector(movement, rotation(world));
}

void player::lateUpdate()
{
	// reset tick based vars
	m_boostIndex = 0;
	m_tickVelocity = 0;
	m_hasBoosted = false;
}

void player::update()
{
	// check the player's input
	playerInput();

	// check if cooldown is over
	checkBoostCooldown();

	printf("vel : %f | pos %.1f, %.1f | boost : %d\n", velocity(), pos(world).x, pos(world).y, m_canBoost);
}

void player::render()
{
	renderTexture();
}
