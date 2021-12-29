#include "levels.h"

levels* levels::s_instance = NULL;

levels* levels::INSTANCE()
{
	if (s_instance == NULL)
		s_instance = new levels();

	return s_instance;
}

levels::levels()
{
	m_currentLevel = menu;

	m_playerChar = new player(Vector2(400, 300));

	m_inputs = inputs::INSTANCE();
	m_physics = physics::INSTANCE();
}

levels::~levels()
{
}

void levels::update()
{
	m_playerChar->update();

	Vector2 movementVec = m_playerChar->getMovement();
	BoundingBox nextFrameBB = m_playerChar->bb(game_entity::world) + movementVec;

	if (physics::INSTANCE()->isGoingToCollide(nextFrameBB))
	{
		m_playerChar->velocity(0);
	}
	else
	{
		m_playerChar->translate(movementVec);
	}

	m_playerChar->lateUpdate();
}

void levels::render()
{
	m_playerChar->render();
}
