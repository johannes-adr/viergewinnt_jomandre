#ifndef VIERGEWINNT_JOMANDRE_PLAYER_H
#define VIERGEWINNT_JOMANDRE_PLAYER_H
#pragma once

#include <string>
#include <memory>
#include "Misc.h"
#include "Board.h"

class Board;

class Player {
private:
    int m_piecesLeft {21};

protected:
    std::weak_ptr<Board> m_board;
public:
    explicit Player();
    ~Player();
    virtual bool play(int position);
    virtual bool giveUp();
    virtual Color getTeam();
    virtual int chooseColumn() = 0;
};

#endif //VIERGEWINNT_JOMANDRE_PLAYER_H
