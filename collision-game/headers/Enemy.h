#ifndef ENEMY_H
#define ENEMY_H

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

  /// @brief returns the nearest player from this Enemy
  /// @return Player*: the nearest player
  Player *getTarget() const { return m_target; };

protected:
  /// @brief sets the nearest player as the target
  /// @param bool randomTarget: when set to true the enemy will grab a random player as target, is off by default
  void setTarget(bool randomTarget = false);
  Color enemyColor() { return RED; };

private:
  Player *m_players[2];
  Player *m_target;
};

#endif