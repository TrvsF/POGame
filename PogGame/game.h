#include "SDL.h"
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

		bool running() { return isRunning; }

	private:
		bool isRunning;
		SDL_Window *window;
		SDL_Renderer *renderer;

		void handleEvents();
		void handleKeyboardDown(SDL_Keycode key);
		void handleKeyboardUp(SDL_Keycode key);
		void update();
		void render();
		void clean();

};
