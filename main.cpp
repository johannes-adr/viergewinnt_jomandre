#include <iostream>

#include "Board.h"
#include <memory>
int main() {
    auto board = std::unique_ptr<Board>();



    std::cout << board->toString()<< std::endl;
    return 0;
}
