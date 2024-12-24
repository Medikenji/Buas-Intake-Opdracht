#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "GlobalVariables.h"

class Player : public Entity
{
public:
	Player();
	~Player();
	void Run(float deltaTime);
	void Draw(sf::RenderWindow& window);

private:
	// @brief handles the input for the player.
	void handleInput();

	static int splayerNum;
	float speed;
	int playerNum;
	sf::CircleShape circle;
};

#endif