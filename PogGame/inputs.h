#pragma once
#include <SDL.h>
/*----------
	input manager class
	handles player inputs

	a. travis 23rd dec
----------*/
class inputs
{
private:

	static inputs* s_instance;

	const Uint8* m_keyboardStates;

	inputs();
	~inputs();

public:

	static inputs* INSTANCE();

	bool keyDown(SDL_Scancode scanCode);
	void update();

};