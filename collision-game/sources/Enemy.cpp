#include "Enemy.h"

Enemy::Enemy(Player *players[2]) {
  for (int i = 0; i < 2; ++i) {
    m_players[i] = players[i];
  }
}

Enemy::~Enemy() {
}

void Enemy::setTarget(bool randomTarget) {
  if (randomTarget) {
    m_target = m_players[GetRandomValue(0, 1)];
    return;
  }
  float distances[2];
  for (int i = 0; i < 2; ++i) {
    float x = this->position.x - m_players[i]->position.x;
    float y = this->position.y - m_players[i]->position.y;
    distances[i] = x * x + y * y;
  }
  m_target = (distances[0] < distances[1]) ? m_players[0] : m_players[1];
}