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
  virtual void Initialise();

private:
  // --- Functions --- //

  /// @brief initialises the level (a wrapper within the constructor)
  void initialiseLevel();

  /// @brief handles the collision between players
  void handlePlayerToPLayerCollision(std::vector<Player *> players);

  /// @brief handles the boundaries of the entities
  void handleBoundaries();

  /// @brief spawns enemies based on a point system
  void handleEnemySpawns(float deltaTime);

  // --- Variables --- //

  // Creating seperate lists and timers for all the entities in the game

  /// @brief the players in the game
  std::vector<Player *> m_Players;

  /// @brief the enemies in the game
  std::vector<Entity *> m_Enemies;
  Timer *m_EnemyTimer;

  /// @brief a seperate deltaTime for the game physics and slo motion suppoert
  float m_gameDeltaTime;

  /// @brief how many points the game manager has
  float m_enemySpawnPoints;
};

#endif