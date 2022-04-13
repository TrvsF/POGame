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
		IDEA :
			CHAR BASED ZOMBO SURVIVAL WITH BUILDING AND WAVES
			BUT WHEN DIE CHAR DIES AND YOU SPAWN FAR AWAY
			SO CAN GET STUFF BACK BUT HARD
			ALSO ONLINE COOP PLS XOXO
		TODO :
			SETTINGS MANAGER
			SOUND MANAGER
			ANIMATED TEXTURES
			MORE ENEMY AI
			MORE WEAPONS
			MAKE ZOMBIE SPEED BASED ON HP
				(IF HP IS VERY LOW CHANGE INTO CRAWLER)
			MAKE TREES/ HOUSES
		BUGS :
			
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