#include "game_entity.h"

game_entity::game_entity(Vector2 vector)
{
	m_pos.x = vector.x;
	m_pos.y = vector.y;

	m_rotation = 0.0f;
	m_velocity = 0.0f;

	m_active = true;
}

game_entity::~game_entity()
{

}

void game_entity::pos(Vector2 pos)
{
	m_pos = pos;
}

Vector2 game_entity::centerPos()
{
	float x = m_texture->width() / 2.0f;
	float y = m_texture->height() / 2.0f;
	return Vector2(m_pos.x - x, m_pos.y - y);
}

Vector2 game_entity::pos()
{
	return m_pos;
}

void game_entity::bb(float x, float y, int width, int height)
{
	m_bb = BoundingBox(x, y, y - height, x - width);
}

void game_entity::bb(BoundingBox bb)
{
	m_bb = bb;
}

BoundingBox game_entity::bb()
{
	return m_bb;
}

void game_entity::rotation(float r)
{
	m_rotation = r;

	if (m_rotation > 360.0f)
		m_rotation -= 360.0f;

	if (m_rotation < 0.0f)
		m_rotation += 360.0f;
}

float game_entity::rotation()
{
	return m_rotation;
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

void game_entity::health(int hp)
{
	m_health = hp;
}

int game_entity::health()
{
	return m_health;
}

void game_entity::takeDamage(int hp, float r)
{
}

void game_entity::type(EntityType t)
{
	m_type = t;
}

game_entity::EntityType game_entity::type()
{
	return m_type;
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
	bb(pos().x, pos().y, m_texture->width(), m_texture->height());
}

void game_entity::drawDebugBB()
{
	SDL_Rect rect;
	rect.x = (int)m_bb.left;
	rect.y = (int)m_bb.top;
	rect.w = (int)m_bb.right - (int)m_bb.left;
	rect.h = (int)m_bb.bottom - (int)m_bb.top;

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