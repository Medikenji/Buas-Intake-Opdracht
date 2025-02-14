#include "GameManager.h"
#include <iostream>

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
  // Made with help from: https://www.jeffreythompson.org/collision-detection/circle-circle.php and my friend Douwe.

  // Cast the entities to players for easier readability.
  Player *a = dynamic_cast<Player *>(players[0]);
  Player *b = dynamic_cast<Player *>(players[1]);

  // Calculate the distance between the players.
  float x = a->position.x - b->position.x;
  float y = a->position.y - b->position.y;
  float distance = x * x + y * y;

  // Handle slow motion
  m_gameDeltaTime /= 1 + ((a->getTotalSpeedInt() + b->getTotalSpeedInt()) / (distance));

  // If the players are colliding
  if (distance <= std::pow(a->scale.x * 1.25 + b->scale.x * 1.25, 2)) {
    // Prevent the players from infinitely colliding
    if (this->m_PlayerTimer->Seconds() != 0) {
      if (this->m_PlayerTimer->Seconds() > 0.5) {
        this->m_PlayerTimer->Stop();
      }
      return;
    }
    this->m_PlayerTimer->Start();

    if (a->getTotalSpeedInt() < 50) {
      a->velocity.x -= b->velocity.x / 2;
      a->velocity.y -= b->velocity.y / 2;
    }
    if (b->getTotalSpeedFloat() < 50) {
      b->velocity.x -= a->velocity.x / 2;
      b->velocity.y -= a->velocity.y / 2;
    }

    // Bounce the players off each other
    a->inverseVelocity(3);
    a->inverseXVelocity(-3);
    b->inverseVelocity(3);
    b->inverseYVelocity(-3);
  }
}

void GameManager::handleBoundaries(std::vector<Entity *> entities, uint8_t type) {
  switch (type) {

    // If the entities are players
  case 1:
    for (int i = 0; i < entities.size(); i++) {
      Entity *entity = entities[i];
      if (entity->inBounds) {
        if (entity->position.x < 0 + entity->scale.x) {
          entity->position.x = 0 + entity->scale.x;
          entity->inverseXVelocity(0.5);
        }
        if (entity->position.x > SCREEN_WIDTH - entity->scale.x) {
          entity->position.x = SCREEN_WIDTH - entity->scale.x;
          entity->inverseXVelocity(0.5);
        }
        if (entity->position.y < 0 + entity->scale.x) {
          entity->position.y = 0 + entity->scale.x;
          entity->inverseYVelocity(0.5);
        }
        if (entity->position.y > SCREEN_HEIGHT - entity->scale.x) {
          entity->position.y = SCREEN_HEIGHT - entity->scale.x;
          entity->inverseYVelocity(0.5);
        }
      }
    }
    break;
    // End of player case
  }
}