#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

// a set of variables to tweak the game from one page

/// @brief sets the size of all in game gui's
#define GUI_SIZE 0.2

/// @brief parameter that controls how many second the players are unable to collide and move after colliding
#define PLAYERCOL_IFRAMES 0.5

/// @brief parameter that controls how fast the player moves
#define PLAYER_SPEED 2.5

/// @brief parameter that controls the max speed the player can go
#define PLAYER_MAX_SPEED 2.0

/// @brief parameter that controls how hard the players launch away when colliding
#define PLAYER_BOUNCE 2.0

/// @brief parameter that controls how hard the players launch away when hitting the edge
#define PLAYER_EDGE_BOUNCE 0.9

#endif