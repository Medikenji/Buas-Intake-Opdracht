#ifndef ENTITY_H
#define ENTITY_H

#include "Cursor.h"
#include "GAME_CONFIG.h"
#include "ProgramConfig.h"
#include "raygui.h"
#include "raylib.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <stdint.h>
#include <vector>

// forward declaration to avoid circular dependency
class Cursor;

/// @brief a base class for all entities
class Entity {
public:
  // --- Functions --- //

  Entity();
  virtual ~Entity();

  /// @brief runs the entity
  /// @param float deltaTime: the time between frames
  virtual void Run(float deltaTime) = 0;

  /// @brief runs the children of the entity
  /// @param float deltaTime: the time between frames
  void runChildren(float deltaTime);

  /// @brief adds an entity to own children
  /// @param Entity* child: the entity to add
  void addChild(Entity *child);

  /// @brief removes an entity from own children
  /// @param Entity* child: the entity to remove
  void removeChild(Entity *child);

  /// @brief gets the children entities
  /// @return std::vector<Entity*>: the children entities
  std::vector<Entity *> &children() { return m_Children; }

  /// @return bool: wether the entity should be in bounds
  bool boundryCheck() { return inBounds; };

  /// @brief sets the marked for deletion status
  void goDie() { m_markedForDeletion = true; }

  // Getters

  /// @brief gets the entity ID
  /// @return int: the entity ID
  int getEID() { return m_EID; }

  /// @brief gets the parent entity
  /// @return Entity*: the parent entity
  Entity *getParent() { return m_Parent; }

  /// @brief gets the velocity of the entity
  /// @return Vector2: the velocity of the entity
  Vector2 getVelocity() const { return velocity; }

  /// @brief gets the scale of the entity
  /// @return Vector2: the scale of the entity
  Vector2 getScale() const { return scale; }

  /// @brief gets the rotation of the entity
  /// @return Vector3: the rotation of the entity
  Vector3 getRotation() const { return rotation; }

  /// @brief gets the total speed of the entity
  /// @return float: the total speed of the entity
  float getTotalSpeed() { return std::sqrt(this->velocity.x * this->velocity.x + this->velocity.y * this->velocity.y); }

  // --- Variables --- //

  // Entity property
  Vector2 position;

protected:
  // --- Functions --- //

  /// @brief gets called after the decronstructor but before the first frames are drawn, can only be called once per object.
  virtual void Initialise() {}

  // --- Variables --- //

  // Entity properties
  Vector2 velocity;
  Vector2 scale;
  Vector3 rotation;

  /// @brief states wether the boundry check should occur on this entity
  bool inBounds;

private:
  // --- Variables --- //

  static int m_s_currentEID;
  int m_EID;
  Entity *m_Parent;
  std::vector<Entity *> m_Children;
  bool m_initialised;
  bool m_markedForDeletion;
};

#endif