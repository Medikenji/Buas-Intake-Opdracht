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
    a->inverseXVelocity(-PLAYER_BOUNCE);
    b->inverseVelocity(PLAYER_BOUNCE);
    b->inverseYVelocity(-PLAYER_BOUNCE);
  }
}

void GameManager::handleBoundaries(std::vector<Entity *> entities, uint8_t type) {
  switch (type) {

    // if the entities are players
  case 1:
    int bounce_strength = 0.5;
    for (int i = 0; i < entities.size(); i++) {
      Entity *entity = entities[i];
      if (entity->inBounds) {
        if (entity->position.x < 0 + entity->scale.x) {
          entity->position.x = 0 + entity->scale.x;
          entity->inverseXVelocity(bounce_strength);
        }
        if (entity->position.x > SCREEN_WIDTH - entity->scale.x) {
          entity->position.x = SCREEN_WIDTH - entity->scale.x;
          entity->inverseXVelocity(bounce_strength);
        }
        if (entity->position.y < 0 + entity->scale.x) {
          entity->position.y = 0 + entity->scale.x;
          entity->inverseYVelocity(bounce_strength);
        }
        if (entity->position.y > SCREEN_HEIGHT - entity->scale.x) {
          entity->position.y = SCREEN_HEIGHT - entity->scale.x;
          entity->inverseYVelocity(bounce_strength);
        }
      }
    }
    break;
    // end of player case
  }
}