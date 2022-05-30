
#include <iostream>
#include "Board/Board.h"
#include "Player.h"

int main() {
    auto board = std::make_unique<Board>();
    printf("%s\n\n",board->toString().c_str());

    auto player1 = std::make_shared<Player>();
    auto player2 = std::make_shared<Player>();

    board->addPlayer(player1);
    board->addPlayer(player2);

    printf("%d", player1->equals(*player1));
    player1->play(0);

    printf("%s",board->toString().c_str());


    return 0;
}

void test(){

}