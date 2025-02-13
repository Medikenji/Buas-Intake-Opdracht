#include "Timer.h"

Timer::Timer() {
  _started = false;
  _paused = false;
  _startTicks = 0;
  _pausedTicks = 0;
}

Timer::~Timer() {
}

void Timer::Start() {
  _started = true;
  _paused = false;
  _startTicks = GetTime();
}

void Timer::Stop() {
  _started = false;
  _paused = false;
  _startTicks = 0;
  _pausedTicks = 0;
}

void Timer::Reset() {
  Stop();
  Start();
}

void Timer::Pause() {
  // Only pause if the timer is running and isn't already paused.
  if (_started && !_paused) {
    _paused = true;
    _pausedTicks = GetTime() - _startTicks;
    _startTicks = 0;
  }
}

void Timer::Unpause() {
  // Only unpause if the timer is running and is paused.
  if (_started && _paused) {
    _paused = false;
    _startTicks = GetTime() - _pausedTicks;
    _pausedTicks = 0;
  }
}

void Timer::TogglePause() {
  if (_paused) {
    Unpause();
  } else {
    Pause();
  }
}

double Timer::Seconds() {
  if (_started) {
    if (_paused) {
      return _pausedTicks;
    } else {
      return GetTime() - _startTicks;
    }
  }
  return 0;
}