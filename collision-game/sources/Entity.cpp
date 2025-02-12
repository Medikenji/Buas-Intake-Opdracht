#include "Entity.h"

int Entity::currentEID = 0;

Entity::Entity() {
  // Initialize the entity
  this->_EID = currentEID++;
  this->_parent = nullptr;
  this->position = {0, 0};
  this->velocity = {0, 0};
  this->scale = {1, 1};
  this->rotation = {0, 0, 0};
  this->inBounds = false;
  this->_markedForDeletion = false;
}

Entity::~Entity() {
  this->_parent = nullptr;
  std::cout << "Entity " << this->_EID << " has been deleted. \n";
}

void Entity::runChildren(float deltaTime) {
  for (int i = 0; i < this->children().size();) {
    if (this->children()[i]->_markedForDeletion) {
      this->removeChild(this->children()[i]);
      this->children()[i]->~Entity();
      i = 0;
    } else {
      this->children()[i]->Run(deltaTime);
      i++;
    }
  }
}

void Entity::addChild(Entity *child) {
  child->_parent = this;
  this->_children.push_back(child);
}

void Entity::removeChild(Entity *child) {
  // Loops through all children and removes the child if found
  for (int i = 0; i < this->_children.size(); i++) {
    if (this->_children[i] == child) {
      this->_children.erase(this->_children.begin() + i);
      break;
    }
  }
}

void Entity::inverseVelocity(float strength) {
  this->velocity = {-this->velocity.x * strength, -this->velocity.y * strength};
}

void Entity::inverseXVelocity(float strength) {
  this->velocity.x = -this->velocity.x * strength;
}

void Entity::inverseYVelocity(float strength) {
  this->velocity.y = -this->velocity.y * strength;
}