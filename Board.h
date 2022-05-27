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

private:
    std::array<std::array<Color, FIELD_WIDTH>, FIELD_HEIGHT> m_fields;
    std::shared_ptr<Player> m_players[2]{};

public:
    explicit Board();
    ~Board();
    virtual bool play(int col);
    std::string toString();
    int getLowestNoneField(int col);
    void reset();
};