/*----------
	level manager class
	handles level loading and all game entities on given levels

	a. travis ~24th dec
----------*/
#ifndef _LEVELS_H
#define _LEVELS_H

#include <SDL.h>
#include "player.h"
#include "wall.h"
#include "physics.h"
#include "projectile.h"

class levels
{
	private:
		levels();
		~levels();

		enum LEVELS { menu, stage1 };

		static levels* s_instance;

		LEVELS m_currentLevel;

		std::list<wall*> m_walls;

		player* m_playerChar;
		physics* m_physics;
		texture* m_title;

	public:
		static levels* INSTANCE();

		void update();
		void render();
};
#endif