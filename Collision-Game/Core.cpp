#include "Core.h"

Core::Core()
{
	sceneManager = new SceneManager();
}

Core::~Core()
{
}

void Core::Run()
{
	// Create the window
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Collide!");
	bool isFocussed = true;
	sf::Event event;

	// Set the max frames per second for easy of physics use
	const int maxFps = 60;
	float deltaTime = 1.0f / maxFps;
	window.setFramerateLimit(maxFps);

	// Run the game loop
	while (window.isOpen())
	{
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			//if (event.type == sf::Event::LostFocus)
			//	isFocussed = false;
			//if (event.type == sf::Event::GainedFocus)
			//	isFocussed = true;
		}
		if (isFocussed)
		{
			window.clear(sf::Color::Black);
			sceneManager->Run(deltaTime);
			window.display();
		}
	}
}