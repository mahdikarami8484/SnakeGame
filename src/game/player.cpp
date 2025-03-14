#include "objects/Player.h"

Player::Player(
            COORD pos, 
            COORD direction,
            COORD start_pos,
            COORD end_pos
)
{
    this->playerBody.push_back({
        pos,
        {0, 0},
        direction,
        start_pos,
        end_pos
    });
}