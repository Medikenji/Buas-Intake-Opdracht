#include "BeamEnemy.h"

BeamEnemy::BeamEnemy(Player *players[2]) : Enemy(players) {
  this->m_onYAxis = GetRandomValue(0, 1);
  this->m_initialized = false;
}

BeamEnemy::~BeamEnemy() {
}

void BeamEnemy::Run(float deltaTime) {

  if (!m_initialized) {
    Rectangle gamescene_boundry = static_cast<GameScene *>(this->getParent()->getParent())->getMapBoundry();
    if (this->m_onYAxis) {
      if (true) {
        this->position.x = gamescene_boundry.x;
      } else {
        this->position.x = gamescene_boundry.width;
      }
      this->position.y = GetRandomValue(gamescene_boundry.y, gamescene_boundry.height);
    }
    this->setTarget(true);
    m_initialized = true;
  }

  DrawCircle(this->position.x, this->position.y, this->scale.x, this->enemyColor());
  DrawLine(this->position.x, this->position.y, this->getTarget()->position.x, this->getTarget()->position.y, this->enemyColor());
}