#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "GlobalVariables.h"

/// @brief handles the player entity.
class Player : public Entity {
public:
  // --- Functions --- //

  Player();
  ~Player();

  virtual void Run(float deltaTime);

private:
  // --- Functions --- //

  /// @brief handles the input for the player, to keep the Run function clean. (Supports max 2 players)
  void handleInput();

  /// @brief handles the size of the player, has a max size of 100. Exists to keep the Run function clean.
  void handleSize();

  // --- Variables --- //
  static int s_playerNum;
  float _speed;
  int _scale;
  int _playerNum;
  Color _playerColor;
};

#endif