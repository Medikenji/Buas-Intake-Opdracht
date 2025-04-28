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
set(EXECUTABLE_NAME Kolvor)
if(UNIX)
    set(EXECUTABLE_NAME Kolvor_open_in_terminal)
endif()

add_executable(${EXECUTABLE_NAME} ${GAME_SOURCES})

# Include directories
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/headers)
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/configurations)

# Link the raylib and raygui libraries
target_link_libraries(${EXECUTABLE_NAME} PRIVATE raylib)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE raygui)