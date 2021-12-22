#include "common.h"
#include "SDL_image.h"
#pragma once

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
		SDL_Window *window;
		SDL_Renderer *renderer;

		void handleEvents();
		void handleKeyboardDown(SDL_Keycode key);
		void handleKeyboardUp(SDL_Keycode key);
		void updateObjects();
		void render();
		void clean();

};
