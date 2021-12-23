#pragma once
#include <SDL.h>

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