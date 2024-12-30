#ifndef BUTTON_H
#define BUTTON_H

#include "Entity.h"

/// @brief a standard button.
class Button : public Entity
{
public:
	// --- Functions --- //

	Button(sf::Vector2f position, sf::Color color, sf::Vector2f scale, const std::string& text = "");
	~Button();

	virtual void Run(float deltaTime);
	virtual void Draw(sf::RenderWindow& window);

	bool isPressed();


	// --- Variables --- //

	sf::Color color;
	std::string text;

private:

	// --- Variables --- //

	sf::RectangleShape _button;
	sf::Text _text;
};

#endif