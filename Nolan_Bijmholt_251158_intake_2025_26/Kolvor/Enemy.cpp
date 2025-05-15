#include "Enemy.h"

float Enemy::m_s_multiplier = 1.0f;

Enemy::Enemy(std::vector<Player *> &players) {
  this->m_Players = players;
}

Enemy::~Enemy() {
}

Vector2 Enemy::getTargetPosition() {
  return this->m_Target->position;
};

void Enemy::s_increaseEnemyDifficulty(float deltaTime) {
  if (m_s_multiplier > 5.0f) {
    m_s_multiplier += 0.005f * deltaTime;
    return;
  }
  m_s_multiplier += 0.01f * deltaTime;
}

void Enemy::setTarget(bool randomTarget) {
  if (randomTarget) {
    this->m_Target = this->m_Players[GetRandomValue(0, 1)];
    return;
  }
  // compare the distances and set the target to the nearest one
  float distances[2];
  for (int i = 0; i < 2; ++i) {
    float x = this->position.x - this->m_Players[i]->position.x;
    float y = this->position.y - this->m_Players[i]->position.y;
    distances[i] = x * x + y * y;
  }
  this->m_Target = (distances[0] < distances[1]) ? this->m_Players[0] : this->m_Players[1];
}

float Enemy::damage(float damageAmount) {
  return damageAmount * m_s_multiplier;
}