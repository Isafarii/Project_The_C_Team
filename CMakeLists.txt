cmake_minimum_required(VERSION 3.10)
project(The_C_Team)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable target with main.cpp and int_stack.cpp, and game.cpp ('gamified' main)
add_executable(main main.cpp int_stack.cpp)
#Game
add_executable(game Game.cpp int_stack.cpp)

