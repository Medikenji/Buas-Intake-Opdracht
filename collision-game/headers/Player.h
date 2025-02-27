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

  /// @brief inverses the full velocity of the player
  /// @param float strength: the strength of the inverse, defaults to 1
  void inverseVelocity(float strength = 1.0f);

  /// @brief inverses the X velocity of the player with a given strength
  /// @param float strength: the strength of the inverse, defaults to 1
  void inverseXVelocity(float strength = 1.0f);

  /// @brief inverses the Y velocity of the player with a given strength
  /// @param float strength: the strength of the inverse, defaults to 1
  void inverseYVelocity(float strength = 1.0f);

  /// @brief temporarily disables the player controls
  void tempDisableInput();

private:
  // --- Functions --- //

  /// @brief handles the input for the player, to keep the Run function clean (Supports max 2 players)
  void handleInput(float deltaTime);

  /// @brief handles the dynamic size of the player, exists to keep the Run function clean
  void handleSize();

  /// @brief dynamically decreases the players health
  void handleHealth(float deltatime);

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