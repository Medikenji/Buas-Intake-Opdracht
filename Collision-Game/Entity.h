#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
public:
	Entity();
	~Entity();

	/// @brief gets the entity ID.
	/// @return int: the entity ID.
	int getEID() { return EID; }

private:
	static int currentEID;
	int EID;
};

#endif