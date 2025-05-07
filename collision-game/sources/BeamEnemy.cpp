#include "BeamEnemy.h"

BeamEnemy::BeamEnemy(Player *players[2]) : Enemy(players) {
  this->scale.x = 5;
  this->position = {static_cast<float>(GetRandomValue(0, ProgramConfig::s_getScreenWidth())), static_cast<float>(GetRandomValue(0, ProgramConfig::s_getScreenHeight()))};
}

BeamEnemy::~BeamEnemy() {
}

void BeamEnemy::Run(float deltaTime) {
  this->setTarget();
  DrawCircle(this->position.x, this->position.y, this->scale.x, this->enemyColor());
  DrawLine(this->position.x, this->position.y, this->getTarget()->position.x, this->getTarget()->position.y, this->enemyColor());
}