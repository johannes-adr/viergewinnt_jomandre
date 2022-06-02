cmake_minimum_required(VERSION 3.22)
project(viergewinnt_jomandre)

set(CMAKE_CXX_STANDARD 17)

add_executable(viergewinnt_jomandre main.cpp Utils/Misc.h Board/Board.cpp Board/Board.h Player/Player.cpp Player/Player.h Player/Bot/Bot.cpp Player/Bot/Bot.h Player/HumanPlayer/HumanPlayer.cpp Player/HumanPlayer/HumanPlayer.h Player/Bot/HorizontalBot.h Player/Bot/HorizontalBot.cpp Player/Bot/RandomBot.h Player/Bot/RandomBot.cpp Player/Bot/SmartBot.h Player/Bot/SmartBot.cpp Player/Bot/VerticalBot.h Player/Bot/VerticalBot.cpp Utils/StackVec.h Utils/Option.h Utils/UniqueObject.h Board/BoardTester.h Utils/Color.h)
