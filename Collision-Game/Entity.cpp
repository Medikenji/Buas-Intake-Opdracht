#include "entity.h"

int Entity::currentEID = 0;

Entity::Entity()
{
	// Initialize the entity
	EID = currentEID++;
	_parent = nullptr;
	position = sf::Vector2f(0, 0);
	velocity = sf::Vector2f(0, 0);
	scale = sf::Vector2f(1, 1);
	rotation = sf::Vector3f(0, 0, 0);
}

Entity::~Entity()
{
}

void Entity::addChild(Entity* child)
{
	child->_parent = this;
	_children.push_back(child);
}

void Entity::removeChild(Entity* child)
{
	// Loops through all children and removes the child if found
	for (int i = 0; i < _children.size(); i++)
	{
		if (_children[i] == child)
		{
			_children.erase(_children.begin() + i);
			break;
		}
	}
}