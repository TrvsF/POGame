#include "common.h"
#pragma once

class timer
{

	public:
		timer();
		~timer();

		void reset();

		float deltaTime();

		void timescale(float t);
		float timescale();

		void update();

private:
	int m_startTicks;
	int m_elapsedTicks;

	float m_deltaTime;
	float m_timeScale;

};
