#ifndef BEAMENEMY_H
#define BEAMENEMY_H

#include "Enemy.h"
#include "GameScene.h"

// forward declaration to avoid circular dependency
class GameScene;

/// @brief an enemy that shoots a laser through the game
class BeamEnemy : public Enemy {
public:
  // --- Functions --- //

  BeamEnemy(Player *players[2]);
  ~BeamEnemy();

  virtual void Run(float deltaTime);

private:
  bool m_onYAxis;
  bool m_initialized;
};

#endif