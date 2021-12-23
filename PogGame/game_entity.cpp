#include "game_entity.h"

game_entity::game_entity(Vector2 vector)
{
	m_pos.x = vector.x;
	m_pos.y = vector.y;

	m_rotation = 0.0f;

	m_active = true;

	m_parent = NULL;
}

game_entity::~game_entity()
{
	m_parent = NULL;
}

void game_entity::pos(Vector2 pos)
{
	m_pos = pos;
}

Vector2 game_entity::pos(SPACE space)
{
	if (space == local || m_parent == NULL)
	{
		return m_pos;
	}
	else
	{
		return m_parent->pos(world) + RotateVector(m_pos, m_parent->rotation(local));
	}
}

void game_entity::rotation(float r)
{
	m_rotation = r;

	if (m_rotation > 360.0f)
		m_rotation -= 360.0f;

	if (m_rotation < 0.0f)
		m_rotation += 360.0f;
}

float game_entity::rotation(SPACE space)
{
	if (space == local || m_parent == NULL)
	{
		return m_rotation;
	}
	else
	{
		return m_parent->rotation(world) + m_rotation;
	}
}

void game_entity::active(bool active)
{
	m_active = active;
}

bool game_entity::active()
{
	return m_active;
}

void game_entity::playerControlled(bool isPlayer)
{
	m_player = isPlayer;
}

bool game_entity::playerControlled()
{
	return m_player;
}

void game_entity::parent(game_entity* parent)
{
	m_pos = pos(world) - parent->pos(world);

	m_parent = parent;
}

game_entity* game_entity::parent()
{
	return m_parent;
}

void game_entity::translate(Vector2 vec)
{
	m_pos += vec;
}

void game_entity::update()
{

}

void game_entity::render()
{
	
}