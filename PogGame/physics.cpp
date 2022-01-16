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

void physics::translateEntitiesNotPlayer(Vector2 vector)
{
	for (auto const& entity : m_gameEntities)
	{
		entity->translate(vector);
	}
}

bool physics::isGoingToCollideWithBB(BoundingBox playerBB)
{		
	for (auto const& entity : m_gameEntities)
	{
		if (entity == nullptr)
			continue;

		if (playerBB.isColliding(entity->bb()))
		{
			printf("collide\n");
			return true;
		}		
	}

	return false;
}

physics::physics()
{
}

physics::~physics()
{
}