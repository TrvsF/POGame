#include "inputs.h"

inputs* inputs::s_instance = NULL;

inputs::inputs()
{
	m_keyboardStates = SDL_GetKeyboardState(&m_keyLength); // epic pass by referance
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

bool inputs::mouseButtonDown(e_mouseButton button)
{
	Uint32 mask = 0;

	switch (button) {
		case left:
			mask = SDL_BUTTON_LMASK;
			break;
		case right:
			mask = SDL_BUTTON_RMASK;
			break;
		case middle:
			mask = SDL_BUTTON_MMASK;
			break;
		case back:
			mask = SDL_BUTTON_X1MASK;
			break;
		case forward:
			mask = SDL_BUTTON_X2MASK;
			break;
	}

	return ((m_mouseState & mask) != 0);
}

bool inputs::mouseButtonPressed(e_mouseButton button)
{
	Uint32 mask = 0;

	switch (button) {
		case left:
			mask = SDL_BUTTON_LMASK;
			break;
		case right:
			mask = SDL_BUTTON_RMASK;
			break;
		case middle:
			mask = SDL_BUTTON_MMASK;
			break;
		case back:
			mask = SDL_BUTTON_X1MASK;
			break;
		case forward:
			mask = SDL_BUTTON_X2MASK;
			break;
	}

	return ((m_prevMouseState & mask) == 0) && ((m_mouseState & mask) != 0);
}

bool inputs::mouseButtonReleased(e_mouseButton button)
{
	Uint32 mask = 0;

	switch (button) {
		case left:
			mask = SDL_BUTTON_LMASK;
			break;
		case right:
			mask = SDL_BUTTON_RMASK;
			break;
		case middle:
			mask = SDL_BUTTON_MMASK;
			break;
		case back:
			mask = SDL_BUTTON_X1MASK;
			break;
		case forward:
			mask = SDL_BUTTON_X2MASK;
			break;
	}

	return ((m_prevMouseState & mask) != 0) && ((m_mouseState & mask) == 0);
}

Vector2 inputs::mousePos()
{
	return Vector2((float)m_mouseX, (float)m_mouseY);
}

void inputs::update()
{
	m_mouseState = SDL_GetMouseState(&m_mouseX, &m_mouseY);
}

void inputs::updatePrev()
{
	copyToPrev();
	m_prevMouseState = m_mouseState;
}
