//
// Created by André on 27.05.2022.
//

#ifndef VIERGEWINNT_JOMANDRE_HUMANPLAYER_H
#define VIERGEWINNT_JOMANDRE_HUMANPLAYER_H
#pragma once

#include "Player.h"

class HumanPlayer : public Player {
public:
    explicit HumanPlayer();
    ~HumanPlayer();
    bool play(int position) override;
};

#endif //VIERGEWINNT_JOMANDRE_HUMANPLAYER_H