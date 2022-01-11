#pragma once
#include "game_entity.h"

class pickups : public game_entity
{
private:


public :
	pickups(int pos);
	~pickups();

	void render();
	void update();



};
