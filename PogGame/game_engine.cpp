#include "game_engine.h"
#include "player.h"

player* player_char;

game_engine::game_engine()
{}

game_engine::~game_engine()
{
	m_assets = NULL;
	m_graphics = NULL;
	m_timer = NULL;
	m_inputs = NULL;
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

	player_char = new player();

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
	m_inputs->update();
	if (m_inputs->keyDown(SDL_SCANCODE_W))
	{
		player_char->translate(VEC2_RIGHT);
	}
}

void game_engine::update()
{
	// entity updates
}

void game_engine::lateUpdate()
{
	m_timer->reset();
}

void game_engine::render()
{
	m_graphics->render();
}
