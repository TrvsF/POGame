#include "graphics.h"

graphics* graphics::s_instance = NULL;

graphics* graphics::INSTANCE()
{
	if (s_instance == NULL)
		s_instance = new graphics();

	return s_instance;
}

graphics::graphics()
{
}

graphics::~graphics()
{
}

bool graphics::init(const char* title, int xPos, int yPos, int width, int hieght, bool fullscreen)
{
	int windowFlags = 0;

	if (fullscreen)
	{
		windowFlags = SDL_WINDOW_FULLSCREEN_DESKTOP;
	}

	// start sdl
	printf("loading SDL...");
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("couldn't initialise SDL: %s\n", SDL_GetError());
		return false;
	}
	printf("done!\n");

	// init sdl window
	printf("init window...");
	m_window = SDL_CreateWindow(title, xPos, yPos, width, hieght, windowFlags);
	if (m_window == NULL)
	{
		printf("couldn't initalise window %s\n", SDL_GetError());
		return false;
	}
	SDL_SetWindowIcon(m_window, texture_helper::loadSurface("./epic_icon.png"));
	printf("done!\n");

	// init sdl renderer
	printf("init renderer...");
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (m_renderer == NULL)
	{
		printf("couldn't initalise renderer %s\n", SDL_GetError());
		return false;
	}
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	printf("done!\n");

	// init sdl image libary
	printf("starting image libary...");
	int flags = IMG_INIT_PNG;
	if (!(IMG_Init(flags) & flags)) {

		printf("couldn't initalise images %s\n", IMG_GetError());
		return false;
	}
	printf("done!\n");

	return true;
}

SDL_Renderer* graphics::renderer()
{
	return m_renderer;
}

void graphics::clearBuffer()
{
	// clear the backbuffer
	SDL_RenderClear(m_renderer);
}

void graphics::render()
{
	// preset the renderer
	SDL_RenderPresent(m_renderer);
}

void graphics::clean()
{
	// clean the window and quit
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
	printf("game cleaned\n");
}
