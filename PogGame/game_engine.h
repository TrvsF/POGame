#pragma once
#include "texture_helper.h"
#include "timer.h"
#include "game_entity.h"
#include "graphics.h"
#include "texture.h"
#include "assets.h"
#include "inputs.h"
#include "levels.h"
/*----------
	game engine class
	handles managers and ensures the game is running correctly

	a. travis 15th dec
----------*/
class game_engine 
{
	private:
		const int FRAME_RATE = 144;

		SDL_Event m_events;

		timer* m_timer;
		graphics* m_graphics;
		assets* m_assets;
		inputs* m_inputs;
		levels* m_levels;

		bool m_isRunning;

		void earlyUpdate();
		void update();
		void lateUpdate();
		void render();

	public:
		game_engine();
		~game_engine();

		bool init();

		void stop();
		void run();

		bool running() { return m_isRunning; }
};
