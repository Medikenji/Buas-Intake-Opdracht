#ifndef BEAMENEMY_H
#define BEAMENEMY_H

#include "Entity.h"

/// @brief runs the full game loop to keep main clear, also creates the window
class BeamEnemy : public Entity {
public:
	// --- Functions --- //

	BeamEnemy();
	~BeamEnemy();

	void Run();

private:
};

#endif