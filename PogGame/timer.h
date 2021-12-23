#pragma once
#include <SDL.h>

class timer
{
	private:
		static timer* s_instance;

		int m_startTicks;
		int m_elapsedTicks;

		float m_deltaTime;
		float m_timeScale;

	public:
		static timer* INSTANCE();

		timer();
		~timer();

		void reset();

		float deltaTime();

		void timescale(float t);
		float timescale();

		void update();
};
