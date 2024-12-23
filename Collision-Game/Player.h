#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();
	void Run(float deltaTime);
	void Draw(sf::RenderWindow& window);

private:
	float speed;
	static int splayerNum;
	int playerNum;
	void handleInput(float deltaTime);
	sf::CircleShape circle;
};

#endif