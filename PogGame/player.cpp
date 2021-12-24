#include "player.h"

player::player(Vector2 position)
{
	pos(position);
	playerControlled(true);
	m_texture = new texture("./character.png");
	m_moving = false;
}

// decrase player velocity over time rather than instantly
float player::calcVelocity()
{
	float velMag = abs(velocity());
	printf("%f\n", velMag);

	// if vel is close to 0 set to 0
	if (velMag < 0.05f)
	{
		velocity(0);
		return velocity();
	}

	if (velocity() > 0)
	{
		velocity(velocity() - 0.05f);
	}
	else
	{
		velocity(velocity() + 0.05f);
	}

	return velocity();
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
	velocity(-2);
}

void player::moveBackward()
{
	velocity(2);
}

void player::moving()
{
	m_moving = true;
}

void player::update()
{
	float y = (m_moving ? velocity() : calcVelocity());
	Vector2 movement = Vector2(0, y);

	translate(RotateVector(movement, rotation(world)));
	m_moving = false;
}

void player::render()
{
	m_texture->render(pos(world), rotation(world));
}
