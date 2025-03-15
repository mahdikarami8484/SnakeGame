#include "objects/game/snake.h"

Snake::Snake(
            Point pos, 
            Point direction,
            Point start_pos,
            Point end_pos
)
{
    this->snakeBody.push_back({
        pos,
        {0, 0},
        direction,
        start_pos,
        end_pos
    });
}