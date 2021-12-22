#pragma once
#include "texture_manager.h"
#include "player_object.h"
#include "timer.h"
#include "game_entity.h"

class game {
	
	public:
		game();
		~game();

		void init(const char* title, int xPos, int yPos, int width, int hieght, bool fullscreen);

		void tick();
		void stop();

		bool running() { return m_isRunning; }

	private:
		const int FRAME_RATE = 144;

		bool m_isRunning;

		SDL_Window *m_window;
		SDL_Renderer *m_renderer;

		void handleEvents();
		void handleKeyboardDown(SDL_Keycode key);
		void handleKeyboardUp(SDL_Keycode key);
		void updateObjects();
		void render();
		void clean();

};
