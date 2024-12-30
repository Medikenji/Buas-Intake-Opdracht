#include "entity.h"

int Entity::currentEID = 0;


Entity::Entity()
{
	// Initialize the entity
	this->EID = currentEID++;
	this->_parent = nullptr;
	this->position = sf::Vector2f(0, 0);
	this->velocity = sf::Vector2f(0, 0);
	this->scale = sf::Vector2f(1, 1);
	this->rotation = sf::Vector3f(0, 0, 0);
	this->inBounds = false;
}

Entity::~Entity()
{
}

void Entity::addChild(Entity* child)
{
	child->_parent = this;
	this->_children.push_back(child);
}

void Entity::removeChild(Entity* child)
{
	// Loops through all children and removes the child if found
	for (int i = 0; i < this->_children.size(); i++)
	{
		if (this->_children[i] == child)
		{
			this->_children.erase(this->_children.begin() + i);
			break;
		}
	}
}

void Entity::inverseVelocity(float strength)
{
	this->velocity = -this->velocity * strength;
}

void Entity::inverseXVelocity(float strength)
{
	this->velocity.x = -this->velocity.x * strength;
}

void Entity::inverseYVelocity(float strength)
{
	this->velocity.y = -this->velocity.y * strength;
}