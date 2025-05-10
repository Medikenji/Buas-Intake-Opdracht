#include "BeamEnemy.h"

BeamEnemy::BeamEnemy(Player *players[2]) : Enemy(players) {
  this->m_flicker = false;
  this->m_timeUntilDetonation = 5.0f / ((Enemy::s_getMultiplier() < 2) ? Enemy::s_getMultiplier() : 2);
  this->m_flickerSpeed = this->m_timeUntilDetonation * 0.1f;
  this->m_detonated = false;
  this->m_explosionThickness = ProgramConfig::s_getScaler() * 0.01f;
}

BeamEnemy::~BeamEnemy() {
}

void BeamEnemy::Run(float deltaTime) {
  this->runChildren(deltaTime);
  flicker(deltaTime);
}

void BeamEnemy::Initialise() {
  Rectangle gamescene_boundry = static_cast<GameScene *>(this->getParent()->getParent())->getMapBoundry();
  if (GetRandomValue(0, 1)) {
    if (GetRandomValue(0, 1)) {
      this->position.x = gamescene_boundry.x;
    } else {
      this->position.x = gamescene_boundry.width + gamescene_boundry.x;
    }
    this->position.y = GetRandomValue(gamescene_boundry.y, gamescene_boundry.height + gamescene_boundry.y);
  } else {
    if (GetRandomValue(0, 1)) {
      this->position.y = gamescene_boundry.y;
    } else {
      this->position.y = gamescene_boundry.height + gamescene_boundry.y;
    }
    this->position.x = GetRandomValue(gamescene_boundry.x, gamescene_boundry.width + gamescene_boundry.x);
  }

  this->setTarget(true);
  setAimVector();
}

void BeamEnemy::setAimVector() {
  Vector2 temp_vector;
  float magnitude;

  // get the vector from the beam to the target
  temp_vector.x = this->getTargetPosition().x - this->position.x;
  temp_vector.y = this->getTargetPosition().y - this->position.y;

  // normalise and move the vector to the BeamEnemy location before enlarging it again
  // made with help from: https://www.khanacademy.org/computing/computer-programming/programming-natural-simulations/programming-vectors/a/vector-magnitude-normalization
  magnitude = sqrt((temp_vector.x * temp_vector.x) + (temp_vector.y * temp_vector.y));
  this->m_aimVector.x = ((temp_vector.x / magnitude * ProgramConfig::s_getNScaler() * 10)) + this->position.x;
  this->m_aimVector.y = ((temp_vector.y / magnitude * ProgramConfig::s_getNScaler() * 10)) + this->position.y;
}

void BeamEnemy::flicker(float deltaTime) {
  this->m_timeUntilDetonation -= deltaTime;
  if (this->m_timeUntilDetonation <= 0) {
    explodeSelf(deltaTime);
    return;
  }
  this->m_flickerSpeed -= deltaTime;
  if (this->m_flickerSpeed <= 0) {
    this->m_flickerSpeed = m_timeUntilDetonation * 0.1f;
    this->m_flicker = !m_flicker;
  }

  if (this->m_flicker && !this->m_detonated) {
    DrawLine(this->position.x, this->position.y, this->m_aimVector.x, this->m_aimVector.y, this->enemyColor());
  }
}

void BeamEnemy::explodeSelf(float deltaTime) {
  if (!m_detonated) {
    // check and handle player to beam collision only once
    Player **players = this->getPlayers();
    for (int i = 0; i < 2; ++i) {
      Player *player = players[i];
      if (player->isStunned()) {
        continue;
      }
      if (CheckCollisionPointLine(player->position, {this->position.x, this->position.y}, {this->m_aimVector.x, this->m_aimVector.y}, player->getScale().x + (ProgramConfig::s_getScaler() * 0.01f) * 1.5f)) {
        player->damagePlayer(this->damage(109.0f));
      }
    }
  }
  m_detonated = true;
  DrawLineEx({this->position.x, this->position.y}, {this->m_aimVector.x, this->m_aimVector.y}, m_explosionThickness, this->enemyColor());
  if (stateI) {
    if (m_explosionThickness < ProgramConfig::s_getScaler() * 0.01f) {
      m_explosionThickness += deltaTime * ProgramConfig::s_getScaler() * 0.25f;
      return;
    }
    stateI = false;
    stateII = true;
  }
  if (stateII) {
    if (m_explosionThickness > 0) {
      m_explosionThickness -= deltaTime * ProgramConfig::s_getScaler() * 0.09f;
      return;
    }
    stateII = false;
  }
  this->goDie();
}