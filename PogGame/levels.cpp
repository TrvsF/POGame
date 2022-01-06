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

	int val = 16;
	for (int i = 0; i < 20; i++)
	{	
		m_walls.push_back(new wall(Vector2(val, 200)));
		val += 16;
	}

	// m_walls.push_back(new wall(Vector2(200, 200)));
}

levels::~levels()
{
}

void levels::update()
{
	m_playerChar->update();

	Vector2 movementVec = m_playerChar->getMovement();
	BoundingBox nextFrameBB = m_playerChar->bb(game_entity::world) + movementVec;

	// check if player is going to collide 
	if (physics::INSTANCE()->isGoingToCollide(nextFrameBB))
	{
		// try and move only 1 axis (for the sliding against the wall effect
		Vector2 xVec = Vector2(movementVec.x, 0);
		Vector2 yVec = Vector2(0, movementVec.y);

		BoundingBox xbb = m_playerChar->bb(game_entity::world) + xVec;
		BoundingBox ybb = m_playerChar->bb(game_entity::world) + yVec;

		if (!physics::INSTANCE()->isGoingToCollide(xbb))
		{
			m_playerChar->translate(xVec);
		}
		if (!physics::INSTANCE()->isGoingToCollide(ybb))
		{
			m_playerChar->translate(yVec);
		}
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
		wall->render();
	}
	m_title->render(Vector2(420, 150), 0);
	m_playerChar->render();
}
