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

void physics::addPlayer(player* player)
{
	m_playerEntities.push_back(player);
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
		if (entity == nullptr)
			continue;

		if (playerBB.isColliding(entity->bb(game_entity::world)))
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