#include "GameManager.h"

GameManager::GameManager() {
  m_PlayerTimer = new Timer();
  m_EnemyTimer = new Timer();
  m_ObjectTimer = new Timer();
  initialiseLevel();
}

GameManager::~GameManager() {
  delete m_PlayerTimer;
  delete m_EnemyTimer;
  delete m_ObjectTimer;
  for (int i = 0; i < m_Enemies.size(); i++) {
    delete m_Enemies[i];
  }
  for (int i = 0; i < m_CollisionObjects.size(); i++) {
    delete m_CollisionObjects[i];
  }
}

void GameManager::Run(float deltaTime) {
  this->m_gameDeltaTime = deltaTime;
  handleBoundaries(m_Players, 1);
  handlePlayerToPLayerCollision(m_Players);
  this->runChildren(m_gameDeltaTime);
}

void GameManager::initialiseLevel() {
  this->m_Players.push_back(new Player());
  this->addChild(m_Players[0]);
  this->m_Players.push_back(new Player());
  this->addChild(m_Players[1]);
}

void GameManager::handlePlayerToPLayerCollision(std::vector<Entity *> players) {
  // made with help from: https://www.jeffreythompson.org/collision-detection/circle-circle.php and my friend Douwe

  // cast the entities to their class to allow Player functions
  Player *a = dynamic_cast<Player *>(players[0]);
  Player *b = dynamic_cast<Player *>(players[1]);

  // calculate the distance between the players
  float x = a->position.x - b->position.x;
  float y = a->position.y - b->position.y;
  float distance = x * x + y * y;

  // handle slow motion
  m_gameDeltaTime /= 1 + ((a->getTotalSpeedInt() + b->getTotalSpeedInt()) / (0.25 * distance));

  // if the players are colliding
  if (distance <= std::pow(a->scale.x + b->scale.x, 2)) {
    // prevent the players from infinitely colliding
    if (this->m_PlayerTimer->Seconds() != 0) {
      if (this->m_PlayerTimer->Seconds() > PLAYERCOL_IFRAMES) {
        this->m_PlayerTimer->Stop();
      }
      return;
    }
    this->m_PlayerTimer->Start();

    // temporarily disable input when colliding
    a->tempDisableInput();
    b->tempDisableInput();

    // add health back
    a->health += a->getTotalSpeedInt() * 0.05;
    if (a->health > 100) {
      a->health = 100;
    }
    b->health += b->getTotalSpeedInt() * 0.05;
    if (b->health > 100) {
      b->health = 100;
    }

    // tranfer velocity if player is standing still
    if (a->getTotalSpeedInt() < 50) {
      a->velocity.x -= b->velocity.x / 2;
      a->velocity.y -= b->velocity.y / 2;
    }
    if (b->getTotalSpeedFloat() < 50) {
      b->velocity.x -= a->velocity.x / 2;
      b->velocity.y -= a->velocity.y / 2;
    }

    // bounce the players off each other
    a->inverseVelocity(PLAYER_BOUNCE);
    b->inverseVelocity(PLAYER_BOUNCE);
  }
}

void GameManager::handleBoundaries(std::vector<Entity *> entities, uint8_t type) {
  switch (type) {

    // if the entities are players
  case 1:
    for (int i = 0; i < entities.size(); i++) {
      Player *player = dynamic_cast<Player *>(entities[i]);
      if (player->inBounds) {
        if (player->position.x < this->position.x + player->scale.x) {
          player->position.x = this->position.x + player->scale.x + 1;
          player->inverseXVelocity(PLAYER_EDGE_BOUNCE);
        }
        if (player->position.x > this->position.x + this->scale.x - player->scale.x) {
          player->position.x = this->position.x + this->scale.x - player->scale.x - 1;
          player->inverseXVelocity(PLAYER_EDGE_BOUNCE);
        }
        if (player->position.y < this->position.y + player->scale.x) {
          player->position.y = this->position.y + player->scale.x + 1;
          player->inverseYVelocity(PLAYER_EDGE_BOUNCE);
        }
        if (player->position.y > this->position.y + this->scale.y - player->scale.x) {
          player->position.y = this->position.y + this->scale.y - player->scale.x - 1;
          player->inverseYVelocity(PLAYER_EDGE_BOUNCE);
        }
      }
    }
    break;
    // end of player case
  }
}