#pragma warning(default:4265)
#include "game_engine.h"
#include <iostream>
/*----------
	main c++ class for POGame
	starts the main program

	a. travis - began work on the 6th Dec 2021
----------*/
game_engine *gameInstance = nullptr;

int main(int argc, char *argv[])
{
	/*
		TODO :
			MORE ENEMY AI
			WEAPON/SHOOTING SYSTEM
				- WEAPON PICKUPS
				- WEAPON TYPES
				- WEAPON SPRITES
			BETTER FEEDBACK WHEN SHOOTING
			PICKUPS
	*/
	printf("STARTING POGame\n\n\n");

	// create instance of the game engine and init it
	gameInstance = new game_engine();

	if (!gameInstance->init())
	{
		std::cin.get();
		return 1;
	}

	// start the game engine
	gameInstance->run();

	// (only ran after game is closed)
	// stop game engine
	gameInstance->stop();

	std::cin.get();

	return 0;
}