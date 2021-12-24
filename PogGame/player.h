#pragma once
#include "game_entity.h"
#include "texture.h"

class player : public game_entity
{
private:
	texture* m_texture;

public:
	player(Vector2 pos);

	void turnRight();
	void turnLeft();
	void moveForward();
	void moveBackward();

	void update();
	void render();
};