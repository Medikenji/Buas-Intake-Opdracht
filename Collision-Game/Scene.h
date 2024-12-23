#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"
#include <iostream>

class Scene : Entity
{
public:
	Scene();
	~Scene();
	void Run(float deltaTime);
	void Draw(sf::RenderWindow &window);

private:
    sf::CircleShape circle;
	float seconds;
};
#endif