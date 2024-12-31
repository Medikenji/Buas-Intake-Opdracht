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

	// @brief runs the entity.
	// @param float deltaTime: the time between frames.
	virtual void Run(float deltaTime) = 0;

	// @brief runs the children of the entity.
	// @param float deltaTime: the time between frames.
	void runChildren(float deltaTime);

	// @brief draws the entity.
	// @param sf::RenderWindow& window: the window to draw to.
	virtual void Draw(sf::RenderWindow &window) = 0;

	// @brief draws the children of the entity.
	// @param sf::RenderWindow& window: the window to draw to.
	void drawChildren(sf::RenderWindow &window);

	// @brief gets the entity ID.
	// @return int: the entity ID.
	int getEID() { return _EID; }

	// @brief adds an entity to own children.
	// @param Entity* child: the entity to add.
	void addChild(Entity* child);

	// @brief removes an entity from own children.
	// @param Entity* child: the entity to remove.
	void removeChild(Entity* child);

	// @brief gets the parent entity.
	// @return Entity*: the parent entity.
	Entity* getParent() { return _parent; }

	// @brief gets the total speed of the entity.
	// @return float: the total speed of the entity.
	float getTotalSpeedFloat() { return sqrt(velocity.x * velocity.x + velocity.y * velocity.y); }

	// @brief gets the total speed of the entity as an integer.
	// @return int: the total speed of the entity as an integer.
	int getTotalSpeedInt() { return (int)getTotalSpeedFloat(); }

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

	// @brief gets the marked for deletion status.
	void goDie() { _markedForDeletion = true; }

	// --- Variables --- //

	// Entity properties
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f scale;
	sf::Vector3f rotation;
	float health;
	bool inBounds;

private:
	// --- Variables --- //
	static int currentEID;
	int _EID;
	Entity* _parent;
	std::vector<Entity*> _children;
	bool _markedForDeletion;
};

#endif