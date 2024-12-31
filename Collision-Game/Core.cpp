#include "Core.h"

Core::Core()
{
	this->sceneManager = new SceneManager();
	this->_deltaTime = 0.0f;
}

Core::~Core()
{
}

void Core::Run()
{
	// Create the window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Collide!", sf::Style::Titlebar | sf::Style::Close);
	bool isFocussed = true;
	sf::Event event;

	// Set the max frames per second a set deltatime for easy of physics use
	window.setFramerateLimit(MAX_FPS);
	this->_deltaTime = 1.0f / MAX_FPS;

	// Run the game loop
	while (window.isOpen())
	{
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			// Render the game in slow motion when focus is lost
			if (event.type == sf::Event::LostFocus)
				isFocussed = false;
			if (event.type == sf::Event::GainedFocus)
				isFocussed = true;
		}

			window.clear(sf::Color::Black);
			if (isFocussed)
			{
				this->_deltaTime = 1.0f / MAX_FPS;
			}
			else
			{
				this->_deltaTime = (1.0f / MAX_FPS) * 0.1f;
			}
            sceneManager->Run(this->_deltaTime);
			sceneManager->Draw(window);
			window.display();
	}
}