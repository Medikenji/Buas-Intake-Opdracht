#include "GameManager.h"

GameManager::GameManager() {
  m_EnemyTimer = new Timer();
  m_ObjectTimer = new Timer();
  initialiseLevel();
}

GameManager::~GameManager() {
  delete m_EnemyTimer;
  delete m_ObjectTimer;
  for (Entity *player : m_Players) {
    player->goDie();
  }
  for (Entity *enemy : m_Enemies) {
    enemy->goDie();
  }
  for (Entity *collisionObject : m_CollisionObjects) {
    collisionObject->goDie();
  }
}

void GameManager::Run(float deltaTime) {
  if (IsKeyPressed(KEY_SPACE)) {
    Player *playersArray[] = {dynamic_cast<Player *>(m_Players[0]), dynamic_cast<Player *>(m_Players[1])};
    this->m_Enemies.push_back(new BeamEnemy(playersArray));
    this->addChild(m_Enemies.back());
  }

  this->m_gameDeltaTime = deltaTime;
  handleBoundaries();
  handlePlayerToPLayerCollision(m_Players);
  this->runChildren(m_gameDeltaTime);
}

void GameManager::initialiseLevel() {

  this->m_Players.push_back(new Player());
  this->addChild(m_Players[0]);
  this->m_Players.push_back(new Player());
  this->addChild(m_Players[1]);
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
  m_gameDeltaTime /= 1 + (((a->getTotalSpeedInt() + b->getTotalSpeedInt()) * ProgramConfig::s_getScaler() * 0.01) / (0.75 * distance));

  // if the players are colliding
  if (distance <= std::pow(a->scale.x + b->scale.x, 2)) {

    // tell players they have collided
    a->Collide(b);
    b->Collide(a);
  }
}

void GameManager::handleBoundaries() {
  // start of player case
  for (Player *player : m_Players) {
    if (player->boundryCheck()) {
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
    // end of player case
  }
}