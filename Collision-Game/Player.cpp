#include "Player.h"

int Player::splayerNum = 0;

Player::Player()
{
	this->playerNum = Player::splayerNum++;
	this->speed = 15;
	this->scale.x = 5;
	this->circle.setRadius(this->scale.x);
	this->circle.setFillColor(sf::Color::Black);
	this->circle.setOutlineThickness(this->scale.y);
	this->circle.setOrigin(this->scale.x, this->scale.x);
	this->inBounds = true;

	// Set the player color and startpos based on player number
	if (playerNum == 0)
	{
		this->position = sf::Vector2f(SCREEN_WIDTH - this->scale.x, SCREEN_HEIGHT - this->scale.x);
		this->circle.setOutlineColor(sf::Color::Magenta);
	}
	else
	{
		this->position = sf::Vector2f(0 + this->scale.x, 0 + this->scale.x);
		this->circle.setOutlineColor(sf::Color::Cyan);
	}
}

Player::~Player()
{
}

void Player::Run(float deltaTime)
{
	this->handleInput();
	this->position += this->velocity * deltaTime;

	// Slow down the player
	this->velocity *= std::pow(0.3f, deltaTime);
}

void Player::Draw(sf::RenderWindow& window)
{
	this->circle.setPosition(this->position.x, this->position.y);
	window.draw(this->circle);
}

void Player::handleInput() {
	if (playerNum == 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			this->velocity.y -= this->speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			this->velocity.y += this->speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			this->velocity.x -= this->speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			this->velocity.x += this->speed;
		}
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			this->velocity.y -= this->speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			this->velocity.y += this->speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			this->velocity.x -= this->speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			this->velocity.x += this->speed;
		}
	}
}