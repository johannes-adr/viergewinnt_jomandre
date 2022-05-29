//
// Created by André on 27.05.2022.
//

#ifndef VIERGEWINNT_JOMANDRE_BOT_H
#define VIERGEWINNT_JOMANDRE_BOT_H
#pragma once

#include "Player.h"

class Bot : public Player {
public:
    virtual bool play(int position) = 0;
    virtual bool giveUp();
    virtual Color getTeam();
};


#endif //VIERGEWINNT_JOMANDRE_BOT_H