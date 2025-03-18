#include "objects/snake.h"

// void Snake::move()
// {
//     this->erase();
    
//     int counter = 0;
//     for(auto& part : this->snakeBody)
//     {
//         part.last_pos = part.pos;

//         if(counter)
//         {
//             part.pos = this->snakeBody[counter-1].last_pos;  
//             continue;
//         }

//         part.pos += part.direction;
//         counter++;
//     }

//     this->draw();
// }

Point Snake::GetLastPos() const {
    return this->_lastPos;
}

void Snake::SetLastPos(Point pos) {
    this->_lastPos = pos;
}

Point Snake::GetDirection() const {
    return this->_direction;
}

void Snake::SetDirection(Point pos) {
    this->_direction = pos;
}

std::string Snake::GetSkin() const
{
    return "o";
}
Graphics::Color Snake::GetForeground() const
{
    return Graphics::Color::BrightGreen;
}

Graphics::Color Snake::GetBackground() const
{
    return Graphics::Color::Black;
}
