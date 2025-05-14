#include "Timer.h"

Timer::Timer() {
  this->m_started = false;
  this->m_paused = false;
  this->m_startTicks = 0.0f;
  this->m_pausedTicks = 0.0f;
}

Timer::~Timer() {
}

void Timer::Start() {
  this->m_started = true;
  this->m_paused = false;
  this->m_startTicks = GetTime();
}

void Timer::Stop() {
  this->m_started = false;
  this->m_paused = false;
  this->m_startTicks = 0.0f;
  this->m_pausedTicks = 0.0f;
}

void Timer::Reset() {
  Stop();
  Start();
}

void Timer::Pause() {
  // Only pause if the timer is running and isn't already paused.
  if (this->m_started && !this->m_paused) {
    this->m_paused = true;
    this->m_pausedTicks = GetTime() - this->m_startTicks;
    this->m_startTicks = 0.0f;
  }
}

void Timer::Unpause() {
  // Only unpause if the timer is running and is paused.
  if (this->m_started && this->m_paused) {
    this->m_paused = false;
    this->m_startTicks = GetTime() - this->m_pausedTicks;
    this->m_pausedTicks = 0.0f;
  }
}

void Timer::togglePause() {
  if (this->m_paused) {
    Unpause();
  } else {
    Pause();
  }
}

double Timer::Seconds() {
  if (this->m_started) {
    if (this->m_paused) {
      return this->m_pausedTicks;
    } else {
      return GetTime() - this->m_startTicks;
    }
  }
  return 0.0f;
}