#include "Player.h"

int Player::splayerNum = 0;

Player::Player() {
  this->playerNum = Player::splayerNum++;
  this->speed = 15;
  this->scale.x = 10;
  this->inBounds = true;

  // Set the player color and startpos based on player number
  if (playerNum == 0) {
    this->position = {SCREEN_WIDTH - this->scale.x, SCREEN_HEIGHT - this->scale.x};
    playerColor = MAGENTA;
  } else {
    this->position = {0 + this->scale.x, 0 + this->scale.x};
    playerColor = SKYBLUE;
  }
}

Player::~Player() {
}

void Player::Run(float deltaTime) {
  this->handleInput();
  this->position.x += this->velocity.x * deltaTime;
  this->position.y += this->velocity.y * deltaTime;

  // Slow down the player
  this->velocity.x *= std::pow(0.3f, deltaTime);
  this->velocity.y *= std::pow(0.3f, deltaTime);

  DrawCircleLines((int)this->position.x, (int)this->position.y, this->scale.x, playerColor);
}

void Player::handleInput() {
  if (playerNum == 0) {
    if (IsKeyDown(KEY_UP)) {
      this->velocity.y -= this->speed;
    }
    if (IsKeyDown(KEY_DOWN)) {
      this->velocity.y += this->speed;
    }
    if (IsKeyDown(KEY_LEFT)) {
      this->velocity.x -= this->speed;
    }
    if (IsKeyDown(KEY_RIGHT)) {
      this->velocity.x += this->speed;
    }
  } else {
    if (IsKeyDown(KEY_W)) {
      this->velocity.y -= this->speed;
    }
    if (IsKeyDown(KEY_S)) {
      this->velocity.y += this->speed;
    }
    if (IsKeyDown(KEY_A)) {
      this->velocity.x -= this->speed;
    }
    if (IsKeyDown(KEY_D)) {
      this->velocity.x += this->speed;
    }
  }
}