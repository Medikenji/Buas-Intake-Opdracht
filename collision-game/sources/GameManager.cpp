#include "GameManager.h"

GameManager::GameManager() {
  this->m_enemySpawnPoints = 3.0f;
}

GameManager::~GameManager() {
  for (Entity *player : this->m_Players) {
    player->goDie();
  }
  for (Entity *enemy : this->m_Enemies) {
    enemy->goDie();
  }
}

void GameManager::Run(float deltaTime) {
  this->m_gameDeltaTime = deltaTime;
  handleBoundaries();
  handlePlayerToPLayerCollision(this->m_Players);
  handleEnemySpawns(this->m_gameDeltaTime);
  Enemy::s_increaseEnemyDifficulty(this->m_gameDeltaTime);
  this->runChildren(this->m_gameDeltaTime);
}

void GameManager::Initialise() {
  this->position = this->getParent()->position;
  this->scale = this->getParent()->getScale();
  initialiseLevel();
}

void GameManager::initialiseLevel() {
  this->m_Players.clear();
  this->m_Players.push_back(new Player());
  this->addChild(this->m_Players[0]);
  this->m_Players.push_back(new Player());
  this->addChild(this->m_Players[1]);
}

void GameManager::handlePlayerToPLayerCollision(std::vector<Player *> players) {

  // made with help from: https://www.jeffreythompson.org/collision-detection/circle-circle.php and my friend Douwe

  // cast the entities to their class to allow Player functions
  Player *a = players[0];
  Player *b = players[1];

  // calculate the distance between the players
  float x = a->position.x - b->position.x;
  float y = a->position.y - b->position.y;
  float distance = x * x + y * y;

  // calculate and implement slow motion
  this->m_gameDeltaTime /= 1 + (((a->getTotalSpeed() + b->getTotalSpeed()) * ProgramConfig::s_getScaler() * 0.01f) / (0.8f * distance));

  // if the players are colliding
  if (distance <= std::pow(a->getScale().x + b->getScale().x, 2.0f)) {

    // tell players they have collided
    a->Collide(b);
    b->Collide(a);
  }
}

void GameManager::handleBoundaries() {
  // start of player case
  for (Player *player : m_Players) {
    if (player->boundryCheck()) {
      if (player->position.x < this->position.x + player->getScale().x) {
        player->position.x = this->position.x + player->getScale().x + 1.0f;
        player->inverseXVelocity(PLAYER_EDGE_BOUNCE);
      }
      if (player->position.x > this->position.x + this->getScale().x - player->getScale().x) {
        player->position.x = this->position.x + this->getScale().x - player->getScale().x - 1.0f;
        player->inverseXVelocity(PLAYER_EDGE_BOUNCE);
      }
      if (player->position.y < this->position.y + player->getScale().x) {
        player->position.y = this->position.y + player->getScale().x + 1.0f;
        player->inverseYVelocity(PLAYER_EDGE_BOUNCE);
      }
      if (player->position.y > this->position.y + this->getScale().y - player->getScale().x) {
        player->position.y = this->position.y + this->getScale().y - player->getScale().x - 1.0f;
        player->inverseYVelocity(PLAYER_EDGE_BOUNCE);
      }
    }
    // end of player case
  }
}

void GameManager::handleEnemySpawns(float deltaTime) {
  this->m_enemySpawnPoints += deltaTime * Enemy::s_getMultiplier() * 1.2f;
  if (this->m_enemySpawnPoints > 5.0f) {
    this->m_enemySpawnPoints -= 5.0f;
    BeamEnemy *beam_enemy = new BeamEnemy(m_Players);
    this->m_Enemies.push_back(beam_enemy);
    addChild(beam_enemy);
  }
}