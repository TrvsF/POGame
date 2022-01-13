#pragma warning(default:4265)
#include "game_engine.h"
#include <iostream>
/*----------
	main c++ class for POGame
	starts the main program

	a. travis & kai - began work on the 6th Dec 2021
----------*/
game_engine *gameInstance = nullptr;

int main(int argc, char *argv[])
{
	/*
		TODO :
		PROJ COLLISON
		WEAPON/SHOOTING SYSTEM
		CAMERA TRACKING [rect and update game objects]
		MAKE UPDATES NOT FPS DEPENDENT <--- fix weird bugs [possbile sync issue?]
		LEVEL SYSTEM
		 - split map into 16x16 (or 32x32) chunks
		 - have maps read and write to file in a 2d array type thingy so you can make & share maps
		 - items and such represented as chars
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