#include "object/game/snake.h"

Snake::Snake(
            COORD pos, 
            COORD direction,
            COORD start_pos,
            COORD end_pos
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