#pragma once
#include <SDL.h>
#include "player.h"
#include "inputs.h"
#include "physics.h"
/*----------
	level manager class
	handles level loading and all game entities on given levels

	a. travis ~24th dec
----------*/
class levels
{
	private:
		levels();
		~levels();

		enum LEVELS { menu, stage1 };

		static levels* s_instance;

		LEVELS m_currentLevel;

		player* m_playerChar;
		inputs* m_inputs;
		physics* m_physics;
		texture* m_title;

	public:
		static levels* INSTANCE();

		void update();
		void render();
};