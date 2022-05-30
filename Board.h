#pragma once
#include "Misc.h"
#include "Player.h"
#include <memory>
#include <array>
#include <map>

class Player;

class Board {
public:
    constexpr static int FIELD_HEIGHT{7};
    constexpr static int FIELD_WIDTH{6};

    Board();
    ~Board();

    Color teamOfPlayer(Player &p);
    virtual bool play(int col);
    int getLowestNoneField(int col);
    void reset();

    std::string toString();
private:
    std::map<std::pair<int,int>,Color> m_fields;
    std::array<std::shared_ptr<Player>,2> m_players{};
};
