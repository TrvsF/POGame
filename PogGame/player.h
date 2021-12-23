#pragma once
#include "game_entity.h"
#include "texture.h"

class player : public game_entity
{
private:
	texture* m_texture;

public:
	player();

	void update();
	void render();
};