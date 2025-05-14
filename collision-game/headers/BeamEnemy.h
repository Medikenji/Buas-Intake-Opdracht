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

  BeamEnemy(std::vector<Player *> &players);
  ~BeamEnemy();

  virtual void Run(float deltaTime);
  virtual void Initialise();

private:
  // --- Functions --- //

  /// @brief sets the aim vector so the beam knows where to be shot
  void setAimVector();

  /// @brief makes the beam flicker when not exploding
  void pulseBeam(float deltaTime);

  /// @brief shoot the beam with an animation before destroying itself
  void explodeSelf(float deltaTime);

  // --- Variables --- //

  Vector2 m_targetPosition;
  /// @brief the vector where the beam aims
  Vector2 m_aimVector;
  float m_timeUntilDetonation;
  /// @brief how quickly the beam should pulse
  float m_pulseSpeed;
  float m_beamWidth;
  bool m_detonated;
  bool m_shouldPulse;

  // animation states for when the beam explodes
  bool stateI = true;
  bool stateII = false;
};

#endif