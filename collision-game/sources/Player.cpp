#include "Player.h"

int Player::m_s_playerNum = 0;

Player::Player() {
  // set instantiate the variables
  this->m_playerNum = Player::m_s_playerNum++;
  this->m_speed = 1000;
  this->m_allowInput = true;
  this->m_scale = 25;
  this->inBounds = true;
  this->m_InputTimer = new Timer();

  // set the player color and startpos based on player number
  if (this->m_playerNum == 0) {
    this->position = {SCREEN_WIDTH - this->scale.x, SCREEN_HEIGHT - this->scale.x};
    this->m_playerColor = MAGENTA;
  } else {
    this->position = {0 + this->scale.x, 0 + this->scale.x};
    m_playerColor = SKYBLUE;
  }
}

Player::~Player() {
  delete m_InputTimer;
}

void Player::Run(float deltaTime) {
  this->handleInput(deltaTime);

  // move the player
  this->position.x += this->velocity.x * deltaTime;
  this->position.y += this->velocity.y * deltaTime;

  // slow down the player
  this->velocity.x *= std::pow(0.1f, deltaTime);
  this->velocity.y *= std::pow(0.1f, deltaTime);

  this->handleSize();

  // draw the player
  DrawCircleLines((int)this->position.x, (int)this->position.y, this->scale.x, m_playerColor);
}

void Player::handleInput(float deltaTime) {
  std::cout << m_allowInput << std::endl;
  if (!m_allowInput) {
    if (m_InputTimer->Seconds() == 0) {
      m_InputTimer->Start();
    }
    if (m_InputTimer->Seconds() > 0.5) {
      m_InputTimer->Stop();
      m_allowInput = true;
    }
    return;
  }
  if (m_playerNum == 0) {
    if (IsKeyDown(KEY_UP)) {
      this->velocity.y -= this->m_speed * deltaTime;
    }
    if (IsKeyDown(KEY_DOWN)) {
      this->velocity.y += this->m_speed * deltaTime;
    }
    if (IsKeyDown(KEY_LEFT)) {
      this->velocity.x -= this->m_speed * deltaTime;
    }
    if (IsKeyDown(KEY_RIGHT)) {
      this->velocity.x += this->m_speed * deltaTime;
    }
  } else {
    if (IsKeyDown(KEY_W)) {
      this->velocity.y -= this->m_speed * deltaTime;
    }
    if (IsKeyDown(KEY_S)) {
      this->velocity.y += this->m_speed * deltaTime;
    }
    if (IsKeyDown(KEY_A)) {
      this->velocity.x -= this->m_speed * deltaTime;
    }
    if (IsKeyDown(KEY_D)) {
      this->velocity.x += this->m_speed * deltaTime;
    }
  }
}

void Player::handleSize() {
  this->scale.x = -this->getTotalSpeedInt() * 0.02 + this->m_scale;
  if (this->scale.x < 5) {
    this->scale.x = 5;
  }
}

void Player::tempDisableInput() {
  m_allowInput = false;
}