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
	m_gameEntities.insert(m_gameEntitiesI, entity);
}

void physics::addPlayer(player* player)
{
	m_playerEntities.insert(m_playerEntitiesI, player);
}

bool physics::isGoingToCollide(BoundingBox playerBB)
{
	if (playerBB.isOutOfBounds(1024, 768))
	{
		printf("out of bounds\n");
		return true;
	}
		
	for (auto const& entity : m_gameEntities)
	{
		if (playerBB.isColliding(entity->bb(game_entity::world)))
		{
			printf("\ncollide\n");
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