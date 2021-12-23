#pragma once
#include <SDL.h>
#include "player.h"
#include "inputs.h"

class levels
{
private:
	levels();
	~levels();

	enum LEVELS { menu, stage1 };

	static levels* s_instance;

	LEVELS m_currentLevel;

	player* m_playerChar;
	inputs* m_inputs;

public:
	static levels* INSTANCE();

	void update();
	void render();

};