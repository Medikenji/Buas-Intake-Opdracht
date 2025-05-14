#define RAYGUI_IMPLEMENTATION
#include "Core.h"

int main() {
  // create a new game instance
  Core *game = new Core();

  // run the game
  game->Run();

  // delete the game instance
  delete game;
  return 0;
}