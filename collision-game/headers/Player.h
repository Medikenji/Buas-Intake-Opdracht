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
  virtual void Initialise();

  static int s_getPlayerPoints() { return (int)m_s_points; }

  /// @brief inverses the full velocity of the player
  /// @param float strength: the strength of the inverse, defaults to 1
  void inverseVelocity(float strength = 1.0f);

  /// @brief inverses the X velocity of the player with a given strength
  /// @param float strength: the strength of the inverse, defaults to 1
  void inverseXVelocity(float strength = 1.0f);

  /// @brief inverses the Y velocity of the player with a given strength
  /// @param float strength: the strength of the inverse, defaults to 1
  void inverseYVelocity(float strength = 1.0f);

  /// @brief handles internal player logic when colliding
  void Collide(Player *otherPlayer);

  /// @brief returns wether the player is stunned
  /// @return bool: true if the player is stunned
  bool isStunned() { return !m_allowInput; };

private:
  // --- Functions --- //

  /// @brief handles the input for the player, to keep the Run function clean (Supports max 2 players)
  void handleInput(float deltaTime);

  /// @brief handles the dynamic size of the player, exists to keep the Run function clean
  void handleSize();

  /// @brief dynamically decreases the players health
  void passiveDamage(float deltaTime);

  // --- Variables --- //

  static int m_s_playerNum;
  static float m_s_points;
  Timer *m_InputTimer;
  Timer *m_PlayerTimer;
  Color m_playerColor;
  Vector2 m_mouseVector;
  bool m_allowInput;
  float m_health;
  float m_speed;
  int m_maxScale;
  int m_playerNum;
};

#endif