#define RAYGUI_IMPLEMENTATION
#include "Core.h"

int main() {
  // Create a new game instance
  Core *game = new Core();

  // Run the game
  game->Run();

  // Delete the game instance
  delete game;
  return 0;
}