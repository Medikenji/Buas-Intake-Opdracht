#include "BeamEnemy.h"

BeamEnemy::BeamEnemy(std::vector<Player *> &players) : Enemy(players) {
  this->m_shouldPulse = false;
  this->m_timeUntilDetonation = BEAM_BASE_SPEED / ((Enemy::s_getMultiplier() < 2.0f) ? Enemy::s_getMultiplier() : 2.0f);
  this->m_pulseSpeed = this->m_timeUntilDetonation * 0.1f;
  this->m_detonated = false;
  this->m_beamWidth = ProgramConfig::s_getScaler() * BEAM_SIZE;
}

BeamEnemy::~BeamEnemy() {
}

void BeamEnemy::Run(float deltaTime) {
  this->runChildren(deltaTime);
  pulseBeam(deltaTime);
}

void BeamEnemy::Initialise() {
  // spawns the beam on a random point in the game boundry
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

  // select a random target and set your aim
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
  this->m_aimVector.x = ((temp_vector.x / magnitude * ProgramConfig::s_getNScaler() * 10.0f)) + this->position.x;
  this->m_aimVector.y = ((temp_vector.y / magnitude * ProgramConfig::s_getNScaler() * 10.0f)) + this->position.y;
}

void BeamEnemy::pulseBeam(float deltaTime) {
  this->m_timeUntilDetonation -= deltaTime;
  if (this->m_timeUntilDetonation <= 0.0f) {
    explodeSelf(deltaTime);
    return;
  }
  this->m_pulseSpeed -= deltaTime;
  if (this->m_pulseSpeed <= 0.0f) {
    this->m_pulseSpeed = this->m_timeUntilDetonation * 0.1f;
    this->m_shouldPulse = !this->m_shouldPulse;
  }

  if (this->m_shouldPulse && !this->m_detonated) {
    DrawLine(this->position.x, this->position.y, this->m_aimVector.x, this->m_aimVector.y, this->enemyColor());
  }
}

void BeamEnemy::explodeSelf(float deltaTime) {
  if (!m_detonated) {
    // check and handle player to beam collision only once
    for (Player *player : this->getPlayers()) {
      if (player->isStunned()) {
        continue;
      }
      if (CheckCollisionPointLine(player->position, {this->position.x, this->position.y}, {this->m_aimVector.x, this->m_aimVector.y}, player->getScale().x + (ProgramConfig::s_getScaler() * BEAM_SIZE) * 1.5f)) {
        player->damagePlayer(this->damage(20.0f));
      }
    }
  }
  m_detonated = true;
  DrawLineEx({this->position.x, this->position.y}, {this->m_aimVector.x, this->m_aimVector.y}, this->m_beamWidth, this->enemyColor());

  // animation for the BeamEnemy
  if (stateI) {
    if (this->m_beamWidth < ProgramConfig::s_getScaler() * BEAM_SIZE) {
      this->m_beamWidth += deltaTime * ProgramConfig::s_getScaler() * BEAM_SIZE * 25.0f;
      return;
    }
    stateI = false;
    stateII = true;
  }
  if (stateII) {
    if (this->m_beamWidth > 0.0f) {
      this->m_beamWidth -= deltaTime * ProgramConfig::s_getScaler() * BEAM_SIZE * 9.0f;
      return;
    }
    stateII = false;
  }
  this->goDie();
}