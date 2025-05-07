#include "Entity.h"

int Entity::m_s_currentEID = 0;

Entity::Entity() {
  // Initialize the entity
  this->m_EID = m_s_currentEID++;
  this->m_Parent = nullptr;
  this->position = {0, 0};
  this->velocity = {0, 0};
  this->scale = {1, 1};
  this->rotation = {0, 0, 0};
  this->inBounds = false;
  this->m_markedForDeletion = false;
}

Entity::~Entity() {
  this->m_Parent = nullptr;
  std::cout << "Entity " << this->m_EID << " has been deleted. \n";
}

void Entity::runChildren(float deltaTime) {
  if (!m_initialised) {
    this->Initialise();
  }
  m_initialised = true;
  for (int i = 0; i < this->children().size();) {
    if (this->children()[i]->m_markedForDeletion) {
      Entity *childToDelete = this->children()[i];
      this->removeChild(childToDelete);
      delete childToDelete;
    } else {
      this->children()[i]->Run(deltaTime);
      i++;
    }
  }
}

void Entity::addChild(Entity *child) {
  child->m_Parent = this;
  this->m_Children.push_back(child);
}

void Entity::removeChild(Entity *child) {
  // Loops through all children and removes the child if found
  for (int i = 0; i < this->m_Children.size(); i++) {
    if (this->m_Children[i] == child) {
      this->m_Children.erase(this->m_Children.begin() + i);
      break;
    }
  }
}