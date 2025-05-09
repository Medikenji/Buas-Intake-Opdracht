#include "Player.h"

int Player::m_s_playerNum = 0;
float Player::m_s_points = 0;

Player::Player() {
  // set instantiate the variables
  this->m_playerNum = Player::m_s_playerNum++;
  this->m_allowInput = true;
  this->m_maxScale = ProgramConfig::s_getScaler() * 0.03f;
  this->inBounds = true;
  this->m_InputTimer = new Timer();
  this->m_PlayerTimer = new Timer();
  this->m_health = 100;
  this->m_mouseVector = {0, 0};
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
  this->velocity.x *= std::pow(0.25f, deltaTime);
  this->velocity.y *= std::pow(0.25f, deltaTime);

  // draw the player
  DrawCircle((int)this->position.x, (int)this->position.y, this->scale.x * m_health * 0.01f, m_playerColor);
  DrawCircleLines((int)this->position.x, (int)this->position.y, this->scale.x, m_playerColor);
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
  std::cout << m_speed << std::endl;

  // sets the mouse vector
  if (GetMouseDelta().y > 0)
    m_mouseVector.y += deltaTime;
  if (GetMouseDelta().y < 0)
    m_mouseVector.y -= deltaTime;
  if (GetMouseDelta().x > 0)
    m_mouseVector.x += deltaTime;
  if (GetMouseDelta().x < 0)
    m_mouseVector.x -= deltaTime;

  // clamp the mouse vector
  m_mouseVector.y = std::clamp(m_mouseVector.y, -0.2f, 0.2f);
  m_mouseVector.x = std::clamp(m_mouseVector.x, -0.2f, 0.2f);

  // only allow input when Iframes havent been called yet
  if (m_allowInput) {
    if (m_playerNum == 0) {
      this->m_playerColor = MAGENTA;
      if (IsKeyDown(KEY_UP) || m_mouseVector.y < -0.1f) {
        this->velocity.y -= this->m_speed * deltaTime;
      }
      if (IsKeyDown(KEY_DOWN) || m_mouseVector.y > 0.1f) {
        this->velocity.y += this->m_speed * deltaTime;
      }
      if (IsKeyDown(KEY_LEFT) || m_mouseVector.x < -0.1f) {
        this->velocity.x -= this->m_speed * deltaTime;
      }
      if (IsKeyDown(KEY_RIGHT) || m_mouseVector.x > 0.1f) {
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

  } else {
    if (m_PlayerTimer->Seconds() > PLAYERCOL_IFRAMES) {
      m_allowInput = true;
    }
    m_playerColor = WHITE;
  }

  // return mouse vector to 0,0
  m_mouseVector.y = m_mouseVector.y + (0.0f - m_mouseVector.y) * (deltaTime);
  m_mouseVector.x = m_mouseVector.x + (0.0f - m_mouseVector.x) * (deltaTime);
}

void Player::handleSize() {
  this->scale.x = -this->getTotalSpeed() * 0.02f + this->m_maxScale;
  if (this->scale.x < ProgramConfig::s_getScaler() * 0.01f) {
    this->scale.x = ProgramConfig::s_getScaler() * 0.01f;
  }
}

void Player::passiveDamage(float deltaTime) {
  this->m_health -= 0.01 * this->m_health * deltaTime;
}

void Player::Collide(Player *otherPlayer) {
  // prevent the players from infinitely colliding
  if (this->m_PlayerTimer->Seconds() != 0) {
    if (this->m_PlayerTimer->Seconds() > PLAYERCOL_IFRAMES) {
      this->m_PlayerTimer->Stop();
    }
    return;
  }

  // tranfer velocity if player is standing still
  if (this->getTotalSpeed() < 50.0f) {
    this->velocity.x -= otherPlayer->velocity.x * 0.5f;
    this->velocity.y -= otherPlayer->velocity.y * 0.5f;
  }

  // start the timer that allows Iframes while disabling the input
  this->m_PlayerTimer->Start();
  m_allowInput = false;

  // add back health to player
  this->m_health += this->getTotalSpeed() * 0.05f;
  if (this->m_health > 100) {
    this->m_health = 100;
  }

  // bounce the players off each other
  this->inverseVelocity(PLAYER_BOUNCE);

  // add points
  m_s_points += getTotalSpeed() * 0.5f;
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