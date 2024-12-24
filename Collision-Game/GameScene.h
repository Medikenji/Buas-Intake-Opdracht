#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "BaseScene.h"
#include "Player.h"
#include "GlobalVariables.h"

class GameScene : public BaseScene
{
public:
	GameScene();
	~GameScene();
	void Run(float deltaTime);
	void Draw(sf::RenderWindow& window);

private:
	void HandleCollisions(Entity* entity);
};

#endif