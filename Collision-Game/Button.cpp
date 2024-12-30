#include "Button.h"

Button::Button(sf::Vector2f position, sf::Color color, sf::Vector2f scale, const std::string& text)
{
	this->position = position;
	this->scale = scale;
	this->color = color;
	this->text = text;
}

Button::~Button()
{
}

void Button::Run(float deltaTime)
{
}

void Button::Draw(sf::RenderWindow& window)
{
	// Draw the button
	this->_button.setPosition(this->position);
	this->_button.setSize(this->scale);
	this->_button.setFillColor(this->color);
	window.draw(this->_button);
}

bool Button::isPressed()
{
	return false;
}