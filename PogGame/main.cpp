#include "SDL.h"
#include "game.h"

game *gameInstance = nullptr;

int main(int argc, char *argv[])
{
	printf("init...\n");

	gameInstance = new game();

	gameInstance->init(
		"POGame",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1024,
		786,
		false
	);

	while (gameInstance->running())
	{
		gameInstance->tick();
	}

	gameInstance->stop();

	std::cin.get();

	return 0;
}