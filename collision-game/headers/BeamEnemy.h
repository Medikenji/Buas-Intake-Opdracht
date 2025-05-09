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
  virtual void Initialise();

private:
  // --- Functions --- //

  /// @brief sets the aim vector so the beam knows where to be shot
  void setAimVector();

  /// @brief makes the beam flicker when not exploding
  void flicker(float deltaTime);

  /// @brief shoot the beam with an animation before destroying itself
  void explodeSelf(float deltaTime);

  // --- Variables --- //
  Vector2 m_targetPosition;
  Vector2 m_aimVector;
  float m_timeUntilDetonation;
  float m_flickerSpeed;
  float m_explosionThickness;
  bool m_detonated;
  bool m_initialized;
  bool m_flicker;

  // animation states
  bool stateI = true;
  bool stateII = false;
};

#endif