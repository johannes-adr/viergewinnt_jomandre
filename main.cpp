
#include <iostream>
#include "Board/Board.h"
#include "Player/HumanPlayer/HumanPlayer.h"
#include "Player/Bot/RandomBot.h"
#include "Player/Bot/HorizontalBot.h"
#include "Board/BoardTester.h"
#include "Player/Bot/VerticalBot.h"

//Board.cpp getLowestNoneField bug return HEIGHT-1??
int main() {
    /*
    auto tester = new TestBoard();
    tester->startTests();

    delete tester;
    */

    auto board = std::make_shared<Board>();
    std::cout << board->toString() << std::endl;

    std::shared_ptr<Player> player1 = std::make_shared<RandomBot>();
    std::shared_ptr<Player> player2 = std::make_shared<RandomBot>();

    Board::addPlayer(board,player1);
    Board::addPlayer(board,player2);

    board->run();
    return 0;
}

void testBoard(){
    auto board = new Board();





    delete board;
}