#include "Player.h"

int Player::m_s_playerNum = 0;

Player::Player() {
  this->m_playerNum = Player::m_s_playerNum++;
  this->m_speed = 15;
  this->m_scale = 5;
  this->inBounds = true;

  // Set the player color and startpos based on player number
  if (this->m_playerNum == 0) {
    this->position = {SCREEN_WIDTH - this->scale.x, SCREEN_HEIGHT - this->scale.x};
    this->m_playerColor = MAGENTA;
  } else {
    this->position = {0 + this->scale.x, 0 + this->scale.x};
    m_playerColor = SKYBLUE;
  }
}

Player::~Player() {
}

void Player::Run(float deltaTime) {
  this->handleInput();

  // Move the player
  this->position.x += this->velocity.x * deltaTime;
  this->position.y += this->velocity.y * deltaTime;

  // Slow down the player
  this->velocity.x *= std::pow(0.3f, deltaTime);
  this->velocity.y *= std::pow(0.3f, deltaTime);

  this->handleSize();

  // Draw the player
  DrawCircleLines((int)this->position.x, (int)this->position.y, this->scale.x, m_playerColor);
}

void Player::handleInput() {
  if (m_playerNum == 0) {
    if (IsKeyDown(KEY_UP)) {
      this->velocity.y -= this->m_speed;
    }
    if (IsKeyDown(KEY_DOWN)) {
      this->velocity.y += this->m_speed;
    }
    if (IsKeyDown(KEY_LEFT)) {
      this->velocity.x -= this->m_speed;
    }
    if (IsKeyDown(KEY_RIGHT)) {
      this->velocity.x += this->m_speed;
    }
  } else {
    if (IsKeyDown(KEY_W)) {
      this->velocity.y -= this->m_speed;
    }
    if (IsKeyDown(KEY_S)) {
      this->velocity.y += this->m_speed;
    }
    if (IsKeyDown(KEY_A)) {
      this->velocity.x -= this->m_speed;
    }
    if (IsKeyDown(KEY_D)) {
      this->velocity.x += this->m_speed;
    }
  }
}

void Player::handleSize() {
  this->scale.x = this->getTotalSpeedInt() * 0.02 + this->m_scale;
  if (this->scale.x > 100) {
    this->scale.x = 100;
  }
}