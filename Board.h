//
// Created by Johannes A. on 26.05.22.
//

#include "Misc.h"
#include "Player.h"
#include <memory>
#include <array>
#pragma once

class Player;

class Board {
public:
    constexpr static int FIELD_HEIGHT{7};
    constexpr static int FIELD_WIDTH{6};

    explicit Board();
    ~Board();
    virtual bool play(int col);
    std::string toString();
    int getLowestNoneField(int col);
private:
    std::array<Color, Color> m_fields{} {};
    std::shared_ptr<Player> m_players[2]{};

};
