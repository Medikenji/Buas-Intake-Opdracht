#ifndef PROGRAM_CONFIG_H
#define PROGRAM_CONFIG_H

// a set of variables that change the behaviour of the program

#define SCREEN_WIDTH  1920
#define SCREEN_HEIGHT 1080

#define MAX_FPS 60

///@brief changes the maximum framerate of the program to 1000 for performance testing
#define PERFORMANCE_TEST 0

#if SCREEN_WIDTH > SCREEN_HEIGHT
#define PRIMARY_Y
#define SCALER     SCREEN_HEIGHT
#define NON_SCALER SCREEN_WIDTH
#else
#define PRIMARY_X
#define SCALER     SCREEN_WIDTH
#define NON_SCALER SCREEN_HEIGHT
#endif

#endif