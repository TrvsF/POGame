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
	const float MAX_VEL = 2;
	const float MAX_VEL_BOOST = 6;
	const float BOOST_MUL[5] = {2.1f, 2.05f, 1.9f, 1.8f};

	texture* m_texture;
	float m_tickVelocity;
	bool m_canBoost;

	float calcVelocity();

public:
	player(Vector2 pos);

	void turnRight();
	void turnLeft();
	void moveForward();
	void moveBackward();
	void boost();

	void update();
	void render();
};