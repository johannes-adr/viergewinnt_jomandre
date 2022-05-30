#include <iostream>
#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "Bot.h"
#include "RandomBot.h"
#include "HorizontalBot.h"
#include "VerticalBot.h"

void printBoard(Board& board) {
    std::cout << board.toString() << std::endl;
}

int main() {
    auto player1 = std::make_shared<HumanPlayer>();
    auto player2 = std::make_shared<VerticalBot>();
    auto board = std::make_unique<Board>();

    return 0;
}