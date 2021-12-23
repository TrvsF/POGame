#pragma once
#include "texture_helper.h"
#include "player_object.h"
#include "timer.h"
#include "game_entity.h"
#include "graphics.h"
#include "texture.h"

class game_engine {
	
	public:
		game_engine();
		~game_engine();

		bool init();

		void stop();
		void run();

		bool running() { return m_isRunning; }

	private:
		const int FRAME_RATE = 144;

		SDL_Event m_events;

		timer* m_timer;
		graphics* m_graphics;
		asset_manager* m_assetManager;

		bool m_isRunning;

		void earlyUpdate();
		void update();
		void lateUpdate();
		void render();

};