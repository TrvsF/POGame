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
	loadLevel("./level.pog");

	
	/*
	m_currentLevelType = menu;

	m_currentLevelTextures.push_back(new texture("terminus.ttf", "POGame", 64, { 255, 0, 0 }));

	m_currentLevelObjects.push_back(new player(Vector2(400, 300)));

	m_currentLevelObjects.push_back(new enemy(Vector2(700, 500)));
	m_currentLevelObjects.push_back(new enemy(Vector2(1200, 500)));

	int val = 16;
	for (int i = 0; i < 20; i++)
	{
		m_currentLevelObjects.push_back(new wall(Vector2((float)val, 200)));
		m_currentLevelObjects.push_back(new wall(Vector2((float)val, 600)));
		val += 16;
	}
	val = 16;
	for (int i = 0; i < 20; i++)
	{
		m_currentLevelObjects.push_back(new wall(Vector2(16, (float)val)));
		m_currentLevelObjects.push_back(new wall(Vector2(416, (float)val)));
		val += 16;
	}
	*/
}

bool levels::loadLevel(std::string fileName)
{
	e_currentReadType currentType;

	std::ifstream file(fileName);

	if (file.is_open()) 
	{
		std::string builder[2];
		std::string currentWord;

		int wordCount = 0;

		currentType = idle;

		while (file >> currentWord)
		{
			// printf("%s\n", currentWord.c_str());
			switch (currentType)
			{
				case idle:
					wordCount = 0;
					builder[wordCount] = currentWord;
					if (builder[wordCount] == "NAME")
					{
						currentType = name;
					}
					if (builder[wordCount] == "TYPE")
					{
						currentType = type;
					}
					if (builder[wordCount] == "WALL")
					{
						currentType = brick;
					}
					if (builder[wordCount] == "PLAYER")
					{
						currentType = character;
					}
					break;
				case name:
					m_levelName = currentWord;
					currentType = idle;
					break;
				case type:
					m_currentLevelType = custom;
					currentType = idle;
					break;
				case brick:
					if (wordCount == 0)
					{
						wordCount++;
						builder[wordCount] = currentWord;
					}
					else
					{
						int x = std::stoi(builder[wordCount]);
						int y = std::stoi(currentWord);
						m_currentLevelObjects.push_back(new wall(Vector2((float)x, (float)y)));
						currentType = idle;
					}
					break;
				case character:
					if (wordCount == 0)
					{
						wordCount++;
						builder[wordCount] = currentWord;
					}
					else
					{
						int x = std::stoi(builder[wordCount]);
						int y = std::stoi(currentWord);
						m_currentLevelObjects.push_back(new player(Vector2((float)x, (float)y)));
						currentType = idle;
					}
					break;
			}
		}
		file.close();
	}
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
