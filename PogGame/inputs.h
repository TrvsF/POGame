/*----------
	input manager class
	handles player inputs

	a. travis 23rd dec
----------*/
#ifndef _INPUTS_H
#define _INPUTS_H

#include <SDL.h>
#include "math_helper.h"

class inputs
{
	private:
		static inputs* s_instance;

		const Uint8* m_keyboardStates;
		Uint8* m_prevKeyboardStates;
		int m_keyLength;

		Uint32 m_prevMouseState;
		Uint32 m_mouseState;

		int m_mouseX;
		int m_mouseY;

		void copyToPrev();

		inputs();
		~inputs();

	public:
		enum e_mouseButton {
			left, right, middle, back, forward
		};

		static inputs* INSTANCE();

		// keyboard
		bool keyDown(SDL_Scancode scanCode);
		bool keyPressed(SDL_Scancode scanCode);
		bool keyReleased(SDL_Scancode scanCode);

		// mouse
		bool mouseButtonDown(e_mouseButton button);
		bool mouseButtonPressed(e_mouseButton button);
		bool mouseButtonReleased(e_mouseButton button);

		Vector2 mousePos();

		void update();
		void updatePrev();
};
#endif