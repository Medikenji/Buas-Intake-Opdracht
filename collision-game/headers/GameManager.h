#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "BeamEnemy.h"
#include "Entity.h"
#include "Player.h"
#include "Timer.h"

// Forward declaration to avoid circular dependency
class Player;
class Timer;

/// @brief handles the game logic
class GameManager : public Entity {
public:
  // --- Functions --- //

  GameManager();
  ~GameManager();

  virtual void Run(float deltaTime);

private:
  // --- Functions --- //

  /// @brief initialises the level (A wrapper within the constructor)
  void initialiseLevel();

  /// @brief handles the collision between players
  /// @param std::vector<Entity*> players: the player entities to check
  void handlePlayerToPLayerCollision(std::vector<Player *> players);

  /// @brief handles the boundaries of the entities
  /// @param std::vector<Entity*> entities: the entities to check
  /// @param uint8_t type: the type of boundary to check
  void handleBoundaries();

  // --- Variables --- //

  // Creating seperate lists and timers for all the entities in the game

  /// @brief the players in the game
  std::vector<Player *> m_Players;

  /// @brief the enemies in the game
  std::vector<Entity *> m_Enemies;
  Timer *m_EnemyTimer;

  /// @brief the stoic collision objects in the game
  std::vector<Entity *> m_CollisionObjects;
  Timer *m_ObjectTimer;

  /// @brief a seperate deltaTime for the game physics
  float m_gameDeltaTime;
};

#endif