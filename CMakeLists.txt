cmake_minimum_required(VERSION 3.6)
project(Game)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Game.cpp Game.h Board.cpp Board.h Player.cpp Player.h HumanPlayer.cpp HumanPlayer.h ComputerPlayer.cpp ComputerPlayer.h utils/State.cpp utils/State.h)
add_executable(Game ${SOURCE_FILES})