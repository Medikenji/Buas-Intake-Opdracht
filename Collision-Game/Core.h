#ifndef CORE_H
#define CORE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "SceneManager.h"
#include "GlobalVariables.h"

/// @Runs the full game loop to keep main clear. Also creates the window.
class Core
{
public:
	Core();
	~Core();
	void Run();

private:
	SceneManager* sceneManager;
	float _deltaTime;
};

#endif