#include "game.h"
#include "texture_manager.h"
#include "player_object.h"
#include "timer.h"

player_object* m_player;
timer* m_timer;

game::game()
{}

game::~game()
{}

void game::init(const char* title, int xPos, int yPos, int width, int hieght, bool fullscreen)
{
	int windowFlags = 0;
	m_isRunning = false;

	if (fullscreen)
	{
		windowFlags = SDL_WINDOW_FULLSCREEN_DESKTOP;
	}

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	window = SDL_CreateWindow(title, xPos, yPos, width, hieght, windowFlags);

	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	if (!window || !renderer)
	{
		printf("something went wrong\n");
		exit(1);
	}

	m_isRunning = true;

	// init player
	m_player = new player_object("./character.png", renderer, 20, 20);
	// init timer
	m_timer = new timer();

}

void game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type) 
		{
			case SDL_QUIT:
				m_isRunning = false;
				break;

			case SDL_KEYDOWN:
				handleKeyboardDown(event.key.keysym.sym);
				break;

			case SDL_KEYUP:
				handleKeyboardUp(event.key.keysym.sym);
				break;
		}
	}
	
}

void game::handleKeyboardDown(SDL_Keycode key)
{
	switch (key)
	{
		case SDLK_w:
			m_player->movementVect[0] = 1;
			break;

		case SDLK_s:
			m_player->movementVect[1] = 1;
			break;

		case SDLK_a:
			m_player->movementVect[2] = 1;
			break;

		case SDLK_d:
			m_player->movementVect[3] = 1;
			break;
	}
}

void game::handleKeyboardUp(SDL_Keycode key)
{
	switch (key)
	{
		case SDLK_w:
			m_player->movementVect[0] = 0;
			break;

		case SDLK_s:
			m_player->movementVect[1] = 0;
			break;

		case SDLK_a:
			m_player->movementVect[2] = 0;
			break;

		case SDLK_d:
			m_player->movementVect[3] = 0;
			break;
	}
}

void game::updateObjects()
{
	m_player->update();
}

void game::render()
{
	SDL_RenderClear(renderer);

	m_player->render();

	SDL_RenderPresent(renderer);
}

void game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	printf("game cleaned\n");
}

// public

void game::tick()
{
	handleEvents();
	updateObjects();
	m_timer->update();
	
	if (m_timer->deltaTime() >= 1.0f / FRAME_RATE)
	{
		render();
		m_timer->reset();
	}

	
}

void game::stop()
{
	clean();
}