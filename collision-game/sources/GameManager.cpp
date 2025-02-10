#include "GameManager.h"
#include <iostream>

GameManager::GameManager() {
  initialiseLevel();
}

GameManager::~GameManager() {
}

void GameManager::Run(float deltaTime) {
  this->_gameDeltaTime = deltaTime;
  handleBoundaries(_players, 1);
  handlePlayerToPLayerCollision(_players);
  this->runChildren(_gameDeltaTime);
}

void GameManager::initialiseLevel() {
  this->_players.push_back(new Player());
  this->addChild(_players[0]);
  this->_players.push_back(new Player());
  this->addChild(_players[1]);
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
  _gameDeltaTime /= 1 + ((a->getTotalSpeedInt() + b->getTotalSpeedInt()) / (5 * distance));

  // If the players are colliding
  if (distance <= std::pow(a->scale.x * 1.25 + b->scale.x * 1.25, 2)) {
    a->inverseVelocity(1.5);
    a->inverseXVelocity(-1.5);
    b->inverseVelocity(1.5);
    b->inverseYVelocity(-1.5);
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