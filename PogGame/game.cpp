#include "game.h"

player_object* m_player;
timer* m_timer;

game_entity* m_parent;
game_entity* m_child;

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

	m_window = SDL_CreateWindow(title, xPos, yPos, width, hieght, windowFlags);

	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

	if (!m_window || !m_renderer)
	{
		printf("something went wrong\n");
		exit(1);
	}

	m_isRunning = true;

	// init player
	m_player = new player_object("./character.png", m_renderer, 20, 20);
	// init timer
	m_timer = new timer();

	m_parent = new game_entity(100, 400);
	m_child = new game_entity(100, 500);

	m_child->parent(m_parent);

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
			m_player->movementVector[0] = 1;
			break;

		case SDLK_s:
			m_player->movementVector[1] = 1;
			break;

		case SDLK_a:
			m_player->movementVector[2] = 1;
			break;

		case SDLK_d:
			m_player->movementVector[3] = 1;
			break;
	}
}

void game::handleKeyboardUp(SDL_Keycode key)
{
	switch (key)
	{
		case SDLK_w:
			m_player->movementVector[0] = 0;
			break;

		case SDLK_s:
			m_player->movementVector[1] = 0;
			break;

		case SDLK_a:
			m_player->movementVector[2] = 0;
			break;

		case SDLK_d:
			m_player->movementVector[3] = 0;
			break;
	}
}

void game::updateObjects()
{
	m_player->update();
}

void game::render()
{
	SDL_RenderClear(m_renderer);

	m_player->render();

	SDL_RenderPresent(m_renderer);
}

void game::clean()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
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