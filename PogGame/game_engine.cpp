#include "game_engine.h"
#include "player.h"

game_engine::game_engine()
{}

game_engine::~game_engine()
{
	m_assets = NULL;
	m_graphics = NULL;
	m_timer = NULL;
	m_inputs = NULL;
	m_levels = NULL;
}

bool game_engine::init()
{
	m_isRunning = false;

	printf("starting graphics...\n");
	m_graphics = graphics::INSTANCE();
	if (m_graphics->init("POGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false))
	{
		printf("graphics started!\n");
		m_isRunning = true;
	}

	// init timer
	printf("loading timer...");
	m_timer = timer::INSTANCE();
	printf("done!\n");

	// init asset manager
	printf("loading asset manager...");
	m_assets = assets::INSTANCE();
	printf("done!\n");

	// init asset manager
	printf("loading input manager...");
	m_inputs = inputs::INSTANCE();
	printf("done!\n");

	// init level manager
	printf("loading level manager...");
	m_levels = levels::INSTANCE();
	printf("done!\n");

	return true;
}

void game_engine::stop()
{
	m_graphics->clean();
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
	m_inputs->update();
}

void game_engine::update()
{
	m_levels->update();
}

void game_engine::lateUpdate()
{
	m_timer->reset();
}

void game_engine::render()
{
	m_graphics->clearBuffer();

	m_levels->render();

	m_graphics->render();
}
