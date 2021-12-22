#include "graphics.h"

texture* m_texture;

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

	printf("loading SDL...");
	// INIT SDL VIDEO AND AUDIO LIBARIES
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("couldn't initialise SDL: %s\n", SDL_GetError());
		return false;
	}
	printf("done!\n");

	printf("init window...");
	// INIT SDL WINDOW
	m_window = SDL_CreateWindow(title, xPos, yPos, width, hieght, windowFlags);
	if (m_window == NULL)
	{
		printf("couldn't initalise window %s\n", SDL_GetError());
		return false;
	}
	printf("done!\n");

	printf("init renderer...");
	// INIT SDL RENDERER
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (m_renderer == NULL)
	{
		printf("couldn't initalise renderer %s\n", SDL_GetError());
		return false;
	}
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	printf("done!\n");

	printf("starting image libary...");
	// INIT SDL IMAGE LIB
	int flags = IMG_INIT_PNG;
	if (!(IMG_Init(flags) & flags)) {

		printf("couldn't initalise images %s\n", IMG_GetError());
		return false;
	}
	printf("done!\n");

	m_texture = new texture("./character.png", m_renderer);

	return true;
}

void graphics::render()
{
	// clear the backbuffer
	SDL_RenderClear(m_renderer);

	m_texture->render();

	// preset the renderer
	SDL_RenderPresent(m_renderer);
}

void graphics::clear()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
	printf("game cleaned\n");
}
