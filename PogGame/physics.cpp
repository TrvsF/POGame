#include "physics.h"

physics* physics::s_instance = NULL;

physics* physics::INSTANCE()
{
	if (s_instance == NULL)
		s_instance = new physics();

	return s_instance;
}

void physics::addEntity(game_entity* entity)
{
	m_gameEntities.push_back(entity);
}

void physics::removeEntity(game_entity* entity)
{
	m_gameEntities.remove(entity);
}

/*
	translates all game entities by a certain vector (not including the player)
*/
void physics::translateEntitiesNotPlayer(Vector2 vector)
{
	for (auto const& entity : m_gameEntities)
	{
		if (entity == nullptr || entity->type() == game_entity::PLAYER)
			continue;

		entity->translate(vector);
	}
}

bool physics::isAnythingNotSelfGoingToCollideWithBB(BoundingBox objectBB, game_entity* self)
{
	for (auto const& entity : m_gameEntities)
	{
		if (entity == nullptr || entity == self)
			continue;

		if (objectBB.isColliding(entity->bb()))
		{
			return true;
		}
	}

	return false;
}

game_entity* physics::getWhatCollidesWithBB(BoundingBox objectBB, game_entity* self, game_entity* parent)
{
	for (auto const& entity : m_gameEntities)
	{
		if (entity == nullptr || entity == self || entity == parent)
			continue;

		if (objectBB.isColliding(entity->bb()))
		{
			return entity;
		}
	}

	return NULL;
}

physics::physics()
{
}

physics::~physics()
{
}