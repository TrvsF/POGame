#include "inputs.h"

inputs* inputs::s_instance = NULL;

inputs::inputs()
{
	m_keyboardStates = SDL_GetKeyboardState(&m_keyLength);
	m_prevKeyboardStates = new Uint8[m_keyLength];
	copyToPrev();
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

void inputs::copyToPrev()
{
	SDL_memcpy(m_prevKeyboardStates, m_keyboardStates, m_keyLength);
}

bool inputs::keyDown(SDL_Scancode scanCode)
{
	return m_keyboardStates[scanCode];
}

bool inputs::keyPressed(SDL_Scancode scanCode)
{
	return (m_prevKeyboardStates[scanCode]) == 0 && (m_keyboardStates[scanCode] != 0);
}

bool inputs::keyReleased(SDL_Scancode scanCode)
{
	return (m_prevKeyboardStates[scanCode]) != 0 && (m_keyboardStates[scanCode] == 0);
}

void inputs::update()
{
	m_keyboardStates = SDL_GetKeyboardState(NULL);
}

void inputs::updatePrev()
{
	copyToPrev();
}
