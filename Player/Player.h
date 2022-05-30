#ifndef VIERGEWINNT_JOMANDRE_PLAYER_H
#define VIERGEWINNT_JOMANDRE_PLAYER_H
#pragma once

#include <string>
#include <memory>
#include "../Utils/Misc.h"
#include "../Board/Board.h"
#include "../Utils/UniqueObject.h"
class Board;

class Player: public UniqueObject{
private:
    int m_piecesLeft {21};

protected:
    std::weak_ptr<Board> m_board;
public:
    explicit Player();
    ~Player();
    void setBoard(std::weak_ptr<Board> b);
    virtual bool play();
    virtual bool giveUp();
    virtual Color getTeam();
    virtual unsigned int chooseColumn() = 0;
};

#endif //VIERGEWINNT_JOMANDRE_PLAYER_H
