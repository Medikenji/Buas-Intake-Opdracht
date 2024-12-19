#include "Director.h"

Director::Director()
{
}

Director::~Director()
{
}

void Director::Run(float deltaTime)
{
	std::cout << "Director " << deltaTime << " running" << std::endl;
}