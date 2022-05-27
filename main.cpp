#include <iostream>
#include <memory>

#include "Board.h"
#include "Player.h"

int main() {
    auto board = std::unique_ptr<Board>();



    std::cout << board->toString()<< std::endl;
    return 0;
}
