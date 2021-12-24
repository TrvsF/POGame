#include "player.h"

player::player(Vector2 position)
{
	pos(position);
	playerControlled(true);
	m_texture = new texture("./character.png");
}

void player::turnRight()
{
	rotation(rotation(world) + 3);
}

void player::turnLeft()
{
	rotation(rotation(world) - 3);
}

void player::moveForward()
{
	velocity(2);

}

void player::moveBackward()
{
	velocity(-2);
}

void player::update()
{
	Vector2 movement = VEC2_ZERO;
	if (velocity() > 0)
	{
		movement = -VEC2_UP;
	}
	if (velocity() < 0)
	{
		movement = VEC2_UP;
	}
	translate(RotateVector(movement, rotation(world)));
}

void player::render()
{
	m_texture->render(pos(world), rotation(world));
}
