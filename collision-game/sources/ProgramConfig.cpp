#include "ProgramConfig.h"

int ProgramConfig::m_s_screenWidth = 0;
int ProgramConfig::m_s_screenHeight = 0;
int ProgramConfig::m_s_scaler = 0;
int ProgramConfig::m_s_nonScaler = 0;

void ProgramConfig::setProgramConfig(int width, int height) {
  m_s_screenWidth = width;
  m_s_screenHeight = height;
  if (width < 400) {
    std::cout << "Width was less then 400, has been set to 400" << std::endl;
    m_s_screenWidth = 400;
  }
  if (height < 400) {
    std::cout << "Height was less then 400, has been set to 400" << std::endl;
    m_s_screenHeight = 400;
  }

  if (m_s_screenWidth < m_s_screenHeight) {
    m_s_scaler = m_s_screenWidth;
    m_s_nonScaler = m_s_screenHeight;
  } else {
    m_s_scaler = m_s_screenHeight;
    m_s_nonScaler = m_s_screenWidth;
  }
}