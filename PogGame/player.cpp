#include "player.h"

player::player(Vector2 position)
{
	pos(position);
	playerControlled(true);
	m_texture = new texture("./character.png");
	m_tickVelocity = 0;
}

// calculate new player velocity given some ammount to add
float player::calcVelocity()
{
	// get what the velocity would be
	float vel = velocity() + m_tickVelocity;
	float velMag = abs(vel);
	// if calculated velocity is over the max then return max veloicty (- or +)
	if (velMag > MAX_VEL)
	{
		return vel > 0 ? MAX_VEL : -MAX_VEL;
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
	// else return the newly calculated velocity
	return vel;
}

void player::turnRight()
{
	rotation(rotation(world) + 3.5f);
}

void player::turnLeft()
{
	rotation(rotation(world) - 3.5f);
}

void player::moveForward()
{
	m_tickVelocity -= 2;
}

void player::moveBackward()
{
	m_tickVelocity += 2;
}

void player::update()
{
	// calculate new velocity and create a movement vector based on value
	velocity(calcVelocity());
	Vector2 movement = Vector2(0, velocity());
	// translate game object and reset this tick's velocity change
	translate(RotateVector(movement, rotation(world)));
	m_tickVelocity = 0;
}

void player::render()
{
	m_texture->render(pos(world), rotation(world));
}
