//
// Created by Johannes A. on 26.05.22.
//

#ifndef VIERGEWINNT_JOMANDRE_PLAYER_H
#define VIERGEWINNT_JOMANDRE_PLAYER_H
#pragma once

#include <string>
#include <memory>
#include "Board.h"

class Board;

class Player {
private:
    int m_piecesLeft {21};
    std::weak_ptr<Board> m_board;

protected:
    const int m_id {0};
    const Color m_team {Color::NONE};

public:
    explicit Player(int id, Color team);
    ~Player();
    virtual bool play(int position) = 0;
    virtual bool giveUp() = 0;
    virtual Color getTeam() = 0;
};

#endif //VIERGEWINNT_JOMANDRE_PLAYER_H