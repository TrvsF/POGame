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

#include "player.h"
#include "wall.h"
#include "enemy.h"
#include "pistol.h"
#include "shotgun.h"
#include "projectile.h"
#include <iostream>
#include <fstream>
#include <string>

class levels
{
	private:
		levels();
		~levels();

		enum e_levelType { menu, story, custom };

		enum e_currentReadType { name, type, brick, character, idle };

		static levels* s_instance;

		std::string m_levelName;

		e_levelType m_currentLevelType;

		std::list<projectile*> m_projectiles;
		std::list<game_entity*> m_currentLevelObjects;
		std::list<texture*> m_currentLevelTextures;

		void resetLevel();

		//------------------//
		// DEBUG OBJECTS
		std::list<wall*> m_walls;

		player* m_playerChar;
		physics* m_physics;
		texture* m_title;
		//------------------//

	public:
		static levels* INSTANCE();

		void loadDefaultLevel();
		bool loadLevel(std::string fileName);

		void addProjectile(projectile* proj);
		void removeProjectile(projectile* proj);

		void update();
		void render();
};
#endif