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

	m_playerChar = new player();

	m_inputs = inputs::INSTANCE();
}

levels::~levels()
{
}

void levels::update()
{
}

void levels::render()
{
	m_playerChar->render();
}
