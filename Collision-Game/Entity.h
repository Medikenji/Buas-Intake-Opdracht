#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System.hpp>
#include <vector>
#include <SFML/Graphics.hpp>

#include "GlobalVariables.h"

/// @brief a base class for all entities.
class Entity
{
public:
	// --- Functions --- //

	Entity();
	~Entity();

	virtual void Run(float deltaTime) = 0;

	virtual void Draw(sf::RenderWindow &window) = 0;

	// @brief gets the entity ID.
	// @return int: the entity ID.
	int getEID() { return EID; }

	// @brief adds an entity to own children.
	// @param Entity* child: the entity to add.
	void addChild(Entity* child);

	// @brief removes an entity from own children.
	// @param Entity* child: the entity to remove.
	void removeChild(Entity* child);

	// @brief gets the parent entity.
	// @return Entity*: the parent entity.
	Entity* getParent() { return _parent; }

	// @brief gets the children entities.
	// @return std::vector<Entity*>: the children entities.
    std::vector<Entity*>& children() { return _children; }

    // @brief inverses the full velocity of the entity.
    // @param float strength: the strength of the inverse.
    void inverseVelocity(float strength = 1.0f);

    // @brief inverses the X velocity of the entity with a given strength.
    // @param float strength: the strength of the inverse.
    void inverseXVelocity(float strength = 1.0f);

    // @brief inverses the Y velocity of the entity with a given strength.
    // @param float strength: the strength of the inverse.
    void inverseYVelocity(float strength = 1.0f);


	// --- Variables --- //

	// Entity properties
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f scale;
	sf::Vector3f rotation;
	bool isCollidable;
	bool inBounds;

private:
	// --- Variables --- //
	static int currentEID;
	int EID;
	Entity* _parent;
	std::vector<Entity*> _children;
};

#endif