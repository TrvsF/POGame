/*----------
	level manager class
	handles level loading and all game entities on given levels

	things a level needs to be loaded
	 - a level type
	 - 

	things a level can contain
	 - the next level

	a. travis ~24th dec
----------*/
#ifndef _LEVELS_H
#define _LEVELS_H

#include <SDL.h>
#include "player.h"
#include "wall.h"
#include "pickups.h"
#include "enemy.h"

class levels
{
	private:
		levels();
		~levels();

		enum e_levelType { menu, story, custom };

		static levels* s_instance;

		e_levelType m_currentLevelType;

		std::list<game_entity*> m_currentLevelObjects;
		std::list<texture*> m_currentLevelTextures;

		void resetLevel();

		//------------------//
		// DEBUG OBJECTS
		std::list<wall*> m_walls;

		player* m_playerChar;
		physics* m_physics;
		texture* m_title;
		pickups* m_pickups;
		//------------------//

	public:
		static levels* INSTANCE();

		void loadDefaultLevel();
		bool loadLevel(std::string name);

		void update();
		void render();
};
#endif