#include "game.h"
#include <iostream>

game *gameInstance = nullptr;

int main(int argc, char *argv[])
{
	printf("init...\n");

	gameInstance = new game();

	gameInstance->init(
		"POGame",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
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