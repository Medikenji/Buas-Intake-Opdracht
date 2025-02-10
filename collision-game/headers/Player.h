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

  // @brief handles the input for the player.
  void handleInput();

  // --- Variables --- //
  static int splayerNum;
  float speed;
  int playerNum;
  Color playerColor;
};

#endif