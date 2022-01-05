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

	m_walls = 
	{
		new wall(Vector2(300, 200)),
		new wall(Vector2(316, 200)),
		new wall(Vector2(332, 200)),
		new wall(Vector2(348, 200)),
		new wall(Vector2(300, 100)),
		new wall(Vector2(316, 100)),
		new wall(Vector2(332, 100)),
		new wall(Vector2(348, 100))
	};
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
	for (auto wall : m_walls)
	{
		if (wall == NULL)
			continue;

		wall->render();
	}
	m_title->render(Vector2(420, 150), 0);
	m_playerChar->render();
}
