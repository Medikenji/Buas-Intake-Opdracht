#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Player.h"

// forward declaration to avoid circular dependency
class Player;

/// @brief defines functions and variables that all enemy types should have
class Enemy : public Entity {
public:
  // --- Functions --- //

  Enemy(Player *players[2]);
  ~Enemy();

  virtual void Run(float deltaTime) = 0;

  /// @brief return all players within the game
  /// @return Player**: a list of all current players
  Player **getPlayers() { return m_players; }

  /// @brief returns the nearest player from this Enemy
  /// @return Player*: the nearest player
  Vector2 getTargetPosition();

  /// @brief returns the enemy multiplier, this dictates their speed and damage
  /// @return float: the multiplier
  static float s_getMultiplier() { return m_s_multiplier; };

  /// @brief increases the difficulty of the enemies every second
  static void s_increaseEnemyDifficulty(float deltaTime);

protected:
  // --- Functions --- //

  /// @brief returns the fully calculated damage with a default base damage as parameter
  /// @return float: the total damage amount
  float damage(float damageAmount);

  /// @brief sets the nearest player as the target
  /// @param bool randomTarget: when set to true the enemy will grab a random player as target, is off by default
  void setTarget(bool randomTarget = false);

  Color enemyColor() { return RED; };

private:
  // --- Variables --- //

  static float m_s_multiplier;
  Player *m_players[2];
  Player *m_target;
};

#endif