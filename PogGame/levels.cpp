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

	m_physics = physics::INSTANCE();

	m_title = new texture("terminus.ttf", "POGame", 64, {255, 0, 0});

	int val = 0;
	for (int i = 0; i < 100; i++)
	{	
		m_walls.push_back(new wall(Vector2(val, 200)));
		val += 16;
	}
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
	for (const auto wall : m_walls)
	{
		if (wall == NULL)
			continue;

		wall->render();
	}
	m_title->render(Vector2(420, 150), 0);
	m_playerChar->render();
}
