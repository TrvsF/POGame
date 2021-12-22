#include "game_engine.h"
#include <iostream>

game_engine *gameInstance = nullptr;

int main(int argc, char *argv[])
{
	printf("init...\n");

	gameInstance = new game_engine();

	if (!gameInstance->init())
	{
		std::cin.get();
		return 1;
	}

	gameInstance->run();

	gameInstance->stop();

	std::cin.get();

	return 0;
}