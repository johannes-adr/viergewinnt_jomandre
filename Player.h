//
// Created by Johannes A. on 26.05.22.
//

#ifndef VIERGEWINNT_JOMANDRE_PLAYER_H
#define VIERGEWINNT_JOMANDRE_PLAYER_H
#pragma once

#include <string>
#include "Misc.h"
#include "Board.h"

class Player {
private:
    int m_piecesLeft {21};
    std::weak_ptr<Board> m_board;

protected:
    const int m_id {0};

public:
    explicit Player(int id);
    ~Player();
    virtual bool play(int position) = 0;
    virtual bool giveUp() = 0;
    virtual Color getTeam() = 0;
};

#endif //VIERGEWINNT_JOMANDRE_PLAYER_H
