#ifndef VIERGEWINNT_JOMANDRE_HORIZONTALBOT_H
#define VIERGEWINNT_JOMANDRE_HORIZONTALBOT_H

#include "Player.h"

class HorizontalBot : public Player {
private:
    int m_pointInRow {-1};
public:
    int chooseColumn() override;
};

#endif //VIERGEWINNT_JOMANDRE_HORIZONTALBOT_H