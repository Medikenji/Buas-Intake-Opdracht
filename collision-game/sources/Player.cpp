#include "Player.h"

int Player::m_s_playerNum = 0;
float Player::m_s_points = 0;

Player::Player() {
  // set instantiate the variables
  this->m_playerNum = Player::m_s_playerNum++;
  this->m_allowInput = true;
  this->m_scale = ProgramConfig::s_getScaler() * 0.03f;
  this->inBounds = true;
  this->m_InputTimer = new Timer();
  this->m_health = 100;

  // set the player color and startpos based on player number
  if (this->m_playerNum == 0) {
    this->position = {ProgramConfig::s_getScreenWidth() - this->scale.x, ProgramConfig::s_getScreenHeight() - this->scale.x};
  } else {
    this->position = {0 + this->scale.x, 0 + this->scale.x};
  }
}

Player::~Player() {
  delete m_InputTimer;
}

void Player::Run(float deltaTime) {
  this->handleInput(deltaTime);
  this->handleSize();
  this->passiveDamage(deltaTime);

  // move the player
  this->position.x += this->velocity.x * deltaTime;
  this->position.y += this->velocity.y * deltaTime;

  // clamp the velocity
  if (this->velocity.x > PLAYER_MAX_SPEED) {
    this->velocity.x = PLAYER_MAX_SPEED;
  }
  if (this->velocity.x < -PLAYER_MAX_SPEED) {
    this->velocity.x = -PLAYER_MAX_SPEED;
  }

  if (this->velocity.y > PLAYER_MAX_SPEED) {
    this->velocity.y = PLAYER_MAX_SPEED;
  }
  if (this->velocity.y < -PLAYER_MAX_SPEED) {
    this->velocity.y = -PLAYER_MAX_SPEED;
  }

  // slow down the player
  this->velocity.x *= std::pow(0.1f, deltaTime);
  this->velocity.y *= std::pow(0.1f, deltaTime);

  // draw the player
  DrawCircle((int)this->position.x, (int)this->position.y, this->scale.x * m_health * 0.01f, m_playerColor);
  DrawCircleLines((int)this->position.x, (int)this->position.y, this->scale.x, m_playerColor);
}

void Player::handleInput(float deltaTime) {
  // disables movement after colliding for a set amount of time
  // NOTE TO SELF: probably gotta refactor this some time
  if (!m_allowInput) {
    if (m_InputTimer->Seconds() == 0) {
      m_InputTimer->Start();
    }
    if (m_InputTimer->Seconds() > PLAYERCOL_IFRAMES) {
      m_InputTimer->Stop();
      m_allowInput = true;
    }
    m_playerColor = WHITE;
    return;
  }
  // sets the speed correctly
  this->m_speed = ProgramConfig::s_getScaler() * 2 * (1 + 1 / this->scale.x);

  if (m_playerNum == 0) {
    this->m_playerColor = MAGENTA;
    if (IsKeyDown(KEY_UP) || GetMouseDelta().y < 0) {
      this->velocity.y -= this->m_speed * deltaTime;
    }
    if (IsKeyDown(KEY_DOWN) || GetMouseDelta().y > 0) {
      this->velocity.y += this->m_speed * deltaTime;
    }
    if (IsKeyDown(KEY_LEFT) || GetMouseDelta().x < 0) {
      this->velocity.x -= this->m_speed * deltaTime;
    }
    if (IsKeyDown(KEY_RIGHT) || GetMouseDelta().x > 0) {
      this->velocity.x += this->m_speed * deltaTime;
    }
  } else {
    m_playerColor = SKYBLUE;
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
  this->scale.x = -this->getTotalSpeedInt() * 0.02f + this->m_scale;
  if (this->scale.x < ProgramConfig::s_getScaler() * 0.01f) {
    this->scale.x = ProgramConfig::s_getScaler() * 0.01f;
  }
}

void Player::passiveDamage(float deltaTime) {
  this->m_health -= 0.1 * this->m_health * deltaTime;
}

void Player::Collide() {
  m_allowInput = false;
  this->m_health += this->getTotalSpeedInt() * 0.05f;
  if (this->m_health > 100) {
    this->m_health = 100;
  }
  m_s_points += getTotalSpeedFloat() * 0.5f;
}

void Player::inverseVelocity(float strength) {
  this->velocity = {-this->velocity.x * strength, -this->velocity.y * strength};
}

void Player::inverseXVelocity(float strength) {
  this->velocity.x = -this->velocity.x * strength;
}

void Player::inverseYVelocity(float strength) {
  this->velocity.y = -this->velocity.y * strength;
}