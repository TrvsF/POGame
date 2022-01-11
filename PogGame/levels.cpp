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

	m_playerChar = new player( Vector2(400, 300) );

	m_physics = physics::INSTANCE();

	m_title = new texture("terminus.ttf", "POGame", 64, {255, 0, 0});

	int val = 16;
	for (int i = 0; i < 20; i++)
	{	
		m_walls.push_back(new wall(Vector2((float)val, 200)));
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
}

void levels::render()
{
	m_pickups->render();
	for (const auto wall : m_walls)
	{
		wall->render();
	}
	m_title->render(Vector2(420, 150), 0);
	m_playerChar->render();
}
