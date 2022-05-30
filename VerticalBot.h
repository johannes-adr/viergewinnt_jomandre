#ifndef VIERGEWINNT_JOMANDRE_VERTICALBOT_H
#define VIERGEWINNT_JOMANDRE_VERTICALBOT_H

#include "Player.h"

class VerticalBot : public Player {
private:
    int m_pointInRow {0};
public:
    int chooseColumn() override;
};

#endif //VIERGEWINNT_JOMANDRE_VERTICALBOT_H