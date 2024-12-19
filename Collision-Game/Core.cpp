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

	// Set the max frames per second a set deltatime for easy of physics use
	const int maxFps = 60;
	const float deltaTime = 1.0f / maxFps;
	window.setFramerateLimit(maxFps);

	// Run the game loop
	while (window.isOpen())
	{
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			// Render the game in slow motion when focus is lost
			if (event.type == sf::Event::LostFocus)
				isFocussed = deltaTime / 4;
			if (event.type == sf::Event::GainedFocus)
				isFocussed = 1.0f / maxFps;
		}
		if (isFocussed)
		{
			window.clear(sf::Color::Black);
			sceneManager->Run(deltaTime);
			window.display();
		}
	}
}