#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System.hpp>
#include <vector>
#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity();
	~Entity();

	virtual void Run(float deltaTime) = 0;

	virtual void Draw(sf::RenderWindow& window) = 0;

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
	std::vector<Entity*> getChildren() { return _children; }

	// Entity properties
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector3f scale;
	sf::Vector3f rotation;

private:
	static int currentEID;
	int EID;
	Entity* _parent;
	std::vector<Entity*> _children;
};

#endif