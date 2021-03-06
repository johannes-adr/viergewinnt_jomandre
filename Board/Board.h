#pragma once
#include "../Utils/Misc.h"
#include "../Player/Player.h"
#include <memory>
#include <array>
#include <map>
#include "../Utils/StackVec.h"
#include <iostream>


class Player;

class Board {
public:
    constexpr static int FIELD_HEIGHT{7};
    constexpr static int FIELD_WIDTH{6};

    Board();
    ~Board();

    Color teamOfPlayer(Player &p);
    virtual bool play(unsigned int col, Player &p);
    int getLowestNoneField(int col);
    void reset();

    bool removePlayer(Player *p);
    std::string toString();

    void run();
    void stop();
    void print();
    bool checkWin();

    static Color addPlayer(std::shared_ptr<Board>& board, std::shared_ptr<Player>& player);

protected:
    std::array<std::array<Color, FIELD_WIDTH>, FIELD_HEIGHT> m_fields{};
    StackVec<std::shared_ptr<Player>,2> m_players{};
    std::atomic<bool> isRunning {true};
};