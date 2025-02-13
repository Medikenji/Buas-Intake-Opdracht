#ifndef TIMER_H
#define TIMER_H

#include "raylib.h"

/// @brief an object that has built in time manage functions.
class Timer {
public:
  // --- Functions --- //

  Timer();
  ~Timer();

  /// @brief starts the timer.
  void Start();

  /// @brief stops the timer.
  void Stop();

  /// @brief resets the timer (calls Start and Stop respectively).
  void Reset();

  /// @brief pauses the timer, different from stopping because it saves the current time.
  void Pause();

  /// @brief unpauses the timer, different from starting because it continues the current time.
  void Unpause();

  /// @brief toggles the pause state of the timer.
  void TogglePause();

  /// @brief gets the time in seconds returns 0 if the timer is stopped.
  /// @return double: the time in seconds.
  double Seconds();

private:
  // --- Variables --- //

  // State handelers.
  bool m_started;
  bool m_paused;
  double m_startTicks;
  double m_pausedTicks;
};

#endif
