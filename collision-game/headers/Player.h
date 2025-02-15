#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Timer.h"

/// @brief handles the player entity
class Player : public Entity {
public:
  // --- Functions --- //

  Player();
  ~Player();
  virtual void Run(float deltaTime);

  void tempDisableInput();

private:
  // --- Functions --- //

  /// @brief handles the input for the player, to keep the Run function clean (Supports max 2 players)
  void handleInput(float deltaTime);

  /// @brief handles the dynamic size of the player, exists to keep the Run function clean
  void handleSize();

  // --- Variables --- //

  static int m_s_playerNum;
  Timer *m_InputTimer;
  bool m_allowInput;
  float m_health;
  float m_speed;
  int m_scale;
  int m_playerNum;
  Color m_playerColor;
};

#endif