#include "entity.h"

int Entity::currentEID = 0;

Entity::Entity()
{
	EID = currentEID++;
}

Entity::~Entity()
{
}