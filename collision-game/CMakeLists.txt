cmake_minimum_required(VERSION 3.10)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Set the project name
project(COLLISION_GAME)

# Add the raylib library
add_subdirectory(libs/raylib-5.5)
add_subdirectory(libs/raygui-4.0/CMake)

# Add the sources
file(GLOB GAME_SOURCES "main.cpp" "sources/*.cpp")

# Add the main executable
add_executable(GameToCollide ${GAME_SOURCES})

# Include directories
target_include_directories(GameToCollide PRIVATE ${CMAKE_SOURCE_DIR}/headers)
target_include_directories(GameToCollide PRIVATE ${CMAKE_SOURCE_DIR}/configurations)

# Link the raylib library
target_link_libraries(GameToCollide PRIVATE raylib)
target_link_libraries(GameToCollide PRIVATE raygui)
