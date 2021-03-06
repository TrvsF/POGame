/*----------
	game engine class
	handles managers and ensures the game is running correctly

	a. travis 15th dec
----------*/
#ifndef _GAME_ENGINE_H
#define _GAME_ENGINE_H

#include "timer.h"
#include "graphics.h"
#include "assets.h"
#include "inputs.h"
#include "levels.h"
#include "physics.h"

class game_engine 
{
	private:
		const int FRAME_RATE = 200;
		const int PHYS_RATE = 150;

		SDL_Event m_events;

		timer* m_gtickTimer;
		timer* m_fpsTimer;

		graphics* m_graphics;
		assets* m_assets;
		inputs* m_inputs;
		levels* m_levels;
		physics* m_physics;

		bool m_isRunning;

		void earlyUpdate();
		void update();
		void lateUpdate();
		void doUpdates();
		void render();

	public:
		game_engine();
		~game_engine();

		bool init();

		void stop();
		void run();

		bool running() { return m_isRunning; }
};
#endif