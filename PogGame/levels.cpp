#include "levels.h"

levels* levels::s_instance = NULL;

levels* levels::INSTANCE()
{
	if (s_instance == NULL)
		s_instance = new levels();

	return s_instance;
}

void levels::loadDefaultLevel()
{
	resetLevel();

	m_currentLevelType = menu;

	m_currentLevelTextures.push_back(new texture("terminus.ttf", "POGame", 64, { 255, 0, 0 }));

	m_currentLevelObjects.push_back(new player(Vector2(400, 300)));

	int val = 16;
	for (int i = 0; i < 20; i++)
	{
		m_currentLevelObjects.push_back(new wall(Vector2((float)val, 200)));
		m_currentLevelObjects.push_back(new wall(Vector2((float)val, 600)));
		val += 16;
	}
}

bool levels::loadLevel(std::string name)
{
	return true;
}

levels::levels()
{
	loadDefaultLevel();
}

levels::~levels()
{
	
}

void levels::resetLevel()
{
	m_currentLevelType = menu;

	m_currentLevelObjects.clear();
	m_currentLevelTextures.clear();
}

void levels::update()
{
	for (auto const& entity : m_currentLevelObjects)
	{
		entity->update();
	}
}

void levels::render()
{
	for (auto const& entity : m_currentLevelObjects)
	{
		entity->render();
	}
	for (auto const& texture : m_currentLevelTextures)
	{
		// TODO : make some sort of system to render in game textures that dont have a game object
	}
}
