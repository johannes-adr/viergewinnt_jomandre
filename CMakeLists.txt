cmake_minimum_required(VERSION 3.22)
project(viergewinnt_jomandre)

set(CMAKE_CXX_STANDARD 17)

add_executable(viergewinnt_jomandre main.cpp Misc.h Board/Board.cpp Board/Board.h Player.cpp Player.h Bot.cpp Bot.h HumanPlayer.cpp HumanPlayer.h Utils/StackVec.h Utils/Option.h Utils/UniqueObject.h)
