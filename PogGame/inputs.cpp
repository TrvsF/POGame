#include "inputs.h"

inputs* inputs::s_instance = NULL;

inputs::inputs()
{

}

inputs::~inputs()
{
}

inputs* inputs::INSTANCE()
{
	if (s_instance == NULL)
		s_instance = new inputs();

	return s_instance;
}

bool inputs::keyDown(SDL_Scancode scanCode)
{
	return m_keyboardStates[scanCode];
}

void inputs::update()
{
	m_keyboardStates = SDL_GetKeyboardState(NULL);
}
