#pragma once
#include "game_entity.h"
#include "texture.h"
/*----------
	player class
	inherits from game entity
	is the game object that the player controls during the game

	a. travis 23rd dec
----------*/
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