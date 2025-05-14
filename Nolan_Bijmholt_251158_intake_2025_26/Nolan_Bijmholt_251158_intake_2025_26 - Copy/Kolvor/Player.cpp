#include "Player.h"

bool Player::m_s_gameOver = false;
int Player::m_s_playerNum = 0;
double Player::m_s_points = 0;
float Player::m_s_pointsMultiplier = 1;

Player::Player() {
  // set instantiate the variables
  this->m_playerNum = Player::m_s_playerNum++;
  this->m_allowInput = true;
  this->m_maxScale = ProgramConfig::s_getScaler() * 0.03f;
  this->inBounds = true;
  this->m_InputTimer = new Timer();
  this->m_PlayerTimer = new Timer();
  this->m_maxHealth = 100;
  this->m_health = this->m_maxHealth;
  this->m_mouseVector = {0.0f, 0.0f};
}

Player::~Player() {
  delete m_InputTimer;
}

void Player::Run(float deltaTime) {
  this->handleInput(deltaTime);
  this->handleSize();
  this->passiveDamage(deltaTime);
  this->handleMultiplier(deltaTime);

  // move the player
  this->position.x += this->velocity.x * deltaTime;
  this->position.y += this->velocity.y * deltaTime;

  float max_speed = PLAYER_MAX_SPEED * ProgramConfig::s_getScaler();
  // clamp the velocity
  if (this->velocity.x > max_speed) {
    this->velocity.x = max_speed;
  }
  if (this->velocity.x < -max_speed) {
    this->velocity.x = -max_speed;
  }

  if (this->velocity.y > max_speed) {
    this->velocity.y = max_speed;
  }
  if (this->velocity.y < -max_speed) {
    this->velocity.y = -max_speed;
  }

  // slow down the player
  this->velocity.x *= std::pow(0.25f, deltaTime);
  this->velocity.y *= std::pow(0.25f, deltaTime);

  // draw the player
  DrawCircle((int)this->position.x, (int)this->position.y, this->scale.x * this->m_health * 0.01f, this->m_playerColor);
  DrawCircleLines((int)this->position.x, (int)this->position.y, this->scale.x, this->m_playerColor);
}

void Player::Initialise() {
  // set the player color and startpos based on player number
  if (this->m_playerNum == 0) {
    this->position = {this->getParent()->position.x, this->getParent()->position.y};
  } else {
    this->position = {
        this->getParent()->position.x + this->getParent()->getScale().x,
        this->getParent()->position.y + this->getParent()->getScale().y,
    };
  }
}

void Player::handleInput(float deltaTime) {
  // sets the speed correctly
  this->m_speed = (ProgramConfig::s_getScaler() / (this->scale.x / m_maxScale)) * 0.25f * PLAYER_SPEED;

  // sets the mouse vector
  if (GetMouseDelta().y > 0.0f)
    this->m_mouseVector.y = 1.0f;
  if (GetMouseDelta().y < 0.0f)
    this->m_mouseVector.y = -1.0f;
  if (GetMouseDelta().x > 0.0f)
    this->m_mouseVector.x = 1.0f;
  if (GetMouseDelta().x < 0.0f)
    this->m_mouseVector.x = -1.0f;

  // clamp the mouse vector
  this->m_mouseVector.y = std::clamp(this->m_mouseVector.y, -0.2f, 0.2f);
  this->m_mouseVector.x = std::clamp(this->m_mouseVector.x, -0.2f, 0.2f);

  // only allow input when Iframes havent been called yet
  if (this->m_allowInput) {
    if (this->m_playerNum == 0) {
      this->m_playerColor = MAGENTA;
      if (IsKeyDown(KEY_UP) || this->m_mouseVector.y < -0.1f) {
        this->velocity.y -= this->m_speed * deltaTime;
      }
      if (IsKeyDown(KEY_DOWN) || this->m_mouseVector.y > 0.1f) {
        this->velocity.y += this->m_speed * deltaTime;
      }
      if (IsKeyDown(KEY_LEFT) || this->m_mouseVector.x < -0.1f) {
        this->velocity.x -= this->m_speed * deltaTime;
      }
      if (IsKeyDown(KEY_RIGHT) || this->m_mouseVector.x > 0.1f) {
        this->velocity.x += this->m_speed * deltaTime;
      }
    } else {
      this->m_playerColor = SKYBLUE;
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

  } else {
    if (this->m_PlayerTimer->Seconds() > PLAYERCOL_IFRAMES) {
      this->m_allowInput = true;
    }
    this->m_playerColor = WHITE;
  }

  // return mouse vector to 0,0
  this->m_mouseVector.y = this->m_mouseVector.y + (-this->m_mouseVector.y * 5.0f) * (deltaTime);
  this->m_mouseVector.x = this->m_mouseVector.x + (-this->m_mouseVector.x * 5.0f) * (deltaTime);
}

void Player::handleSize() {
  this->scale.x = -this->getTotalSpeed() * 0.02f + this->m_maxScale;
  if (this->scale.x < ProgramConfig::s_getScaler() * 0.01f) {
    this->scale.x = ProgramConfig::s_getScaler() * 0.01f;
  }
}

void Player::passiveDamage(float deltaTime) {
  this->m_health -= 0.05f * this->m_health * Enemy::s_getMultiplier() * deltaTime;
}

void Player::handleMultiplier(float deltaTime) {
  if (m_s_pointsMultiplier <= 1.0f) {
    m_s_pointsMultiplier = 1.0f;
    return;
  }
  m_s_pointsMultiplier -= m_s_pointsMultiplier * 0.1f * deltaTime;
}

void Player::Collide(Player *otherPlayer) {
  // prevent the players from infinitely colliding
  if (this->m_PlayerTimer->Seconds() != 0.0f) {
    if (this->m_PlayerTimer->Seconds() > PLAYERCOL_IFRAMES) {
      this->m_PlayerTimer->Stop();
    }
    return;
  }

  // tranfer velocity if player is standing still
  if (this->getTotalSpeed() < 50.0f) {
    this->velocity.x += otherPlayer->velocity.x * 0.5f;
    this->velocity.y += otherPlayer->velocity.y * 0.5f;
  }

  // start the timer that allows Iframes and disable input
  this->m_PlayerTimer->Start();
  this->m_allowInput = false;

  // add back health to player
  this->m_health += this->getTotalSpeed() * 0.05f;
  if (this->m_health > 100.0f) {
    this->m_health = 100.0f;
  }

  // bounce the players off each other, also prevents easy infinite colliding
  this->inverseVelocity(PLAYER_BOUNCE * 0.75f);
  if (std::abs(this->velocity.x) < 1.0f) {
    this->velocity.x += GetRandomValue(-this->m_speed, this->m_speed);
  }
  if (m_playerNum == 0) {
    this->inverseXVelocity(-PLAYER_BOUNCE * 1.25f);
  } else {
    if (std::abs(this->velocity.y) < 1) {
      this->velocity.y += GetRandomValue(-this->m_speed, this->m_speed);
    }
    this->inverseYVelocity(-PLAYER_BOUNCE * 1.25f);
  }

  // add points and multiplier
  m_s_pointsMultiplier += 0.01f * getTotalSpeed() + Enemy::s_getMultiplier();
  m_s_points += getTotalSpeed() * 0.1f * m_s_pointsMultiplier;
}

void Player::damagePlayer(float damageAmount) {
  // start the timer that allows Iframes and disable input
  this->m_PlayerTimer->Start();
  m_allowInput = false;

  if (damageAmount > this->m_maxHealth && this->m_health > this->m_maxHealth * 0.3f) {
    this->m_health = this->m_maxHealth * 0.1f;
    return;
  }
  this->m_health -= damageAmount;

  if (this->m_health < 0.0f) {
    m_s_gameOver = true;
  }
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