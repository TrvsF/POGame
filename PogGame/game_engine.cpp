#include "game_engine.h"

game_engine::game_engine()
{}

game_engine::~game_engine()
{}

bool game_engine::init()
{
	m_isRunning = false;

	printf("starting graphics...\n");
	m_graphics = new graphics();
	if (m_graphics->init("POGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false))
	{
		printf("graphics started!\n");
		m_isRunning = true;
	}

	// init timer
	m_timer = new timer();

	return true;
}

void game_engine::stop()
{
	m_graphics->clear();
}

void game_engine::run()
{
	while (m_isRunning) {

		m_timer->update();

		while (SDL_PollEvent(&m_events) != 0) {
			switch (m_events.type)
			{
				case SDL_QUIT:
					m_isRunning = false;
					break;
			}
		}

		// 144 times a second refresh the renderer
		if (m_timer->deltaTime() >= 1.0f / FRAME_RATE)
		{
			earlyUpdate();
			update();
			lateUpdate();
			render();
		}

	}
}

void game_engine::earlyUpdate()
{
}

void game_engine::update()
{
}

void game_engine::lateUpdate()
{
}

void game_engine::render()
{
	m_graphics->render();
}
