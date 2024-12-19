#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <iostream>
#include "Entity.h"

class Director : Entity
{
public:
	Director();
	~Director();
	virtual void Run(float deltaTime);
};

#endif