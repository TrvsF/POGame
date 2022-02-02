#include "pistol.h"

void pistol::onPickup(game_entity* pickeruper)
{
	pos(pickeruper->pos());
	setTexture("arms.png");

	physics::INSTANCE()->removePickup(this);
}

pistol::pistol(Vector2 position)
{
	pos(position);
	setTexture("pickup_pistol.png");

	physics::INSTANCE()->addPickup(this);
}

pistol::~pistol()
{
}

void pistol::shoot()
{

}

void pistol::update()
{
}

void pistol::render()
{
	renderTexture();
}
