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
		Uint8* m_prevKeyboardStates;
		int m_keyLength;

		void copyToPrev();

		inputs();
		~inputs();

	public:

		static inputs* INSTANCE();

		bool keyDown(SDL_Scancode scanCode);
		bool keyPressed(SDL_Scancode scanCode);
		bool keyReleased(SDL_Scancode scanCode);

		void update();
		void updatePrev();
};