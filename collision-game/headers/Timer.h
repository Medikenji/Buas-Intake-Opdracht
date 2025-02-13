#ifndef TIMER_H
#define TIMER_H

#include "raylib.h"

/// @brief an object that has built in time manage functions.
class Timer {
public:
  // --- Functions --- //

  Timer();
  ~Timer();

  void Start();
  void Reset();
  void Pause();
  void Unpause();
  void TogglePause();
  double Seconds();

private:
  // --- Variables --- //
  bool _started;
  bool _paused;
  double _startTicks;
  double _pausedTicks;
};

#endif
