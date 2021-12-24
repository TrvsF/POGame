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
}

levels::~levels()
{
}

void levels::update()
{
	if (m_inputs->keyDown(SDL_SCANCODE_W))
	{
		m_playerChar->moving();
		m_playerChar->moveForward();
	}
	if (m_inputs->keyDown(SDL_SCANCODE_S))
	{
		m_playerChar->moving();
		m_playerChar->moveBackward();
	}
	if (m_inputs->keyDown(SDL_SCANCODE_D))
	{
		m_playerChar->turnRight();
	}
	if (m_inputs->keyDown(SDL_SCANCODE_A))
	{
		m_playerChar->turnLeft();
	}
	m_playerChar->update();
}

void levels::render()
{
	m_playerChar->render();
}
