#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "Entity.h"
#include "director.h"

/// @brief handles the gameplay scene.
class GameScene : public Entity
{
public:
	GameScene();
	~GameScene();
	virtual void Run(float deltaTime);
	virtual void Draw(sf::RenderWindow& window);

private:
	Director* _gameDirector;
};

#endif