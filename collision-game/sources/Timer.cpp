#include "Timer.h"

Timer::Timer() {
  m_started = false;
  m_paused = false;
  m_startTicks = 0;
  m_pausedTicks = 0;
}

Timer::~Timer() {
}

void Timer::Start() {
  m_started = true;
  m_paused = false;
  m_startTicks = GetTime();
}

void Timer::Stop() {
  m_started = false;
  m_paused = false;
  m_startTicks = 0;
  m_pausedTicks = 0;
}

void Timer::Reset() {
  Stop();
  Start();
}

void Timer::Pause() {
  // Only pause if the timer is running and isn't already paused.
  if (m_started && !m_paused) {
    m_paused = true;
    m_pausedTicks = GetTime() - m_startTicks;
    m_startTicks = 0;
  }
}

void Timer::Unpause() {
  // Only unpause if the timer is running and is paused.
  if (m_started && m_paused) {
    m_paused = false;
    m_startTicks = GetTime() - m_pausedTicks;
    m_pausedTicks = 0;
  }
}

void Timer::togglePause() {
  if (m_paused) {
    Unpause();
  } else {
    Pause();
  }
}

double Timer::Seconds() {
  if (m_started) {
    if (m_paused) {
      return m_pausedTicks;
    } else {
      return GetTime() - m_startTicks;
    }
  }
  return 0;
}