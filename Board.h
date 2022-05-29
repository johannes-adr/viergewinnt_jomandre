//
// Created by Johannes A. on 26.05.22.
//
#pragma once
#include "Misc.h"
#include "Player.h"
#include <memory>
#include <array>


class Player;

class Board {
public:
    constexpr static int FIELD_HEIGHT{7};
    constexpr static int FIELD_WIDTH{6};

    explicit Board();
    ~Board();

    Color teamOfPlayer(Player &p);
    virtual bool play(int col);
    int getLowestNoneField(int col);
    void reset();


    std::string toString();
private:
    Color m_fields[7][6]{};
    std::shared_ptr<Player> m_players[2]{};

};
