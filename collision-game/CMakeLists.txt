cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

project(Project)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/headers
)
add_subdirectory(libs/raylib-5.5)
add_subdirectory(libs/raygui-4.0/CMake)

file(GLOB PROJECT_SOURCES "main.cpp" "sources/*.cpp" "headers/*.h")

# Add the main executable
add_executable(Project ${PROJECT_SOURCES})

# Link the raylib library
target_link_libraries(Project PRIVATE raylib)
target_link_libraries(Project PRIVATE raygui)