#include "game_entity.h"

game_entity::game_entity(Vector2 vector)
{
	m_pos.x = vector.x;
	m_pos.y = vector.y;

	m_rotation = 0.0f;
	m_velocity = 0.0f;

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

void game_entity::bb(float x, float y, int width, int height)
{
	m_bb = BoundingBox(x, y, y - height, x - width);
}

void game_entity::bb(BoundingBox bb)
{
	m_bb = bb;
}

BoundingBox game_entity::bb(SPACE space)
{
	if (space == local || m_parent == NULL)
	{
		return m_bb;
	}
	else
	{
		return m_parent->bb(world) + bb(world);
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

void game_entity::velocity(float vel)
{
	m_velocity = vel;
}

float game_entity::velocity()
{
	return m_velocity;
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

void game_entity::setTexture(std::string path)
{
	m_texture = new texture(path);
	setBB();
}

void game_entity::renderTexture()
{
	m_texture->render(m_pos, m_rotation);
}

void game_entity::translate(Vector2 vec)
{
	m_pos += vec;
	m_bb += vec;
}

void game_entity::setBB()
{
	bb(pos(world).x, pos(world).y, m_texture->width(), m_texture->height());
}

void game_entity::drawDebugBB()
{
	SDL_Rect rect;
	rect.x = m_bb.left;
	rect.y = m_bb.top;
	rect.w = m_bb.right - m_bb.left;
	rect.h = m_bb.bottom - m_bb.top;

	SDL_SetRenderDrawColor(graphics::INSTANCE()->renderer(), 255, 0, 0, 255);
	SDL_RenderDrawRect(graphics::INSTANCE()->renderer(), &rect);

	SDL_SetRenderDrawColor(graphics::INSTANCE()->renderer(), 255, 255, 255, 255);

}

void game_entity::update()
{

}

void game_entity::render()
{
	
}