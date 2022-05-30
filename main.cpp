
#include <iostream>
#include "Board/Board.h"
#include "Player/HumanPlayer/HumanPlayer.h"
#include "Player/Bot/RandomBot.h"
#include "Player/Bot/HorizontalBot.h"

int main() {
    auto board = std::make_shared<Board>();
    std::cout << board->toString() << std::endl;

    std::shared_ptr<Player> player1 = std::make_shared<HumanPlayer>();
    std::shared_ptr<Player> player2 = std::make_shared<RandomBot>();

    Board::addPlayer(board,player1);
    Board::addPlayer(board,player2);

    player1->play();
    player2->play();
    std::cout << board->toString() << std::endl;

    player1->play();
    player2->play();
    std::cout << board->toString() << std::endl;

    player1->play();
    player2->play();
    std::cout << board->toString() << std::endl;

    player1->play();
    player2->play();
    std::cout << board->toString() << std::endl;

    player1->play();
    player2->play();
    std::cout << board->toString() << std::endl;

    player1->play();
    player2->play();
    std::cout << board->toString() << std::endl;

    player1->play();
    player2->play();
    std::cout << board->toString() << std::endl;

    player1->play();
    player2->play();
    std::cout << board->toString() << std::endl;

    return 0;
}

void test(){

}