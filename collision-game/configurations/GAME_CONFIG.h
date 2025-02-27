#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

// a set of variables to tweak the game feel from one page

/// @brief parameter that controls how many second the players are unable to collide and move after colliding
#define PLAYERCOL_IFRAMES 0.5

/// @brief parameter that controls the max speed the player can go
#define PLAYER_MAX_SPEED 15000.0

/// @brief parameter that controls how hard the players launch away when colliding
#define PLAYER_BOUNCE 4.0

/// @brief parameter that controls how hard the players launch away when hitting the edge
#define PLAYER_EDGE_BOUNCE 0.9

#endif