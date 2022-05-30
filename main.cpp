#include <iostream>
#include "Board.h"
#include "Player.h"

int main() {
    auto board = std::make_unique<Board>();
    std::cout << board->toString() << std::endl;
    auto player1 = std::make_shared<Player>();
    auto player2 = std::make_shared<Player>();

    return 0;
}