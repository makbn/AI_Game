cmake_minimum_required(VERSION 3.6)
project(Game)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Game.cpp Game.h Board.cpp Board.h Players/Player.cpp Players/Player.h Players/HumanPlayer.cpp Players/HumanPlayer.h Players/ComputerPlayer.cpp Players/ComputerPlayer.h Utils/State.cpp Utils/State.h Players/NetworkPlayer.cpp Players/NetworkPlayer.h Utils/SocketClient.cpp)
add_executable(Game ${SOURCE_FILES})