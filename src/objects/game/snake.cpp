#include "objects/game/snake.h"

Snake::Snake(
            Point pos, 
            Point direction,
)
{
    this->snakeBody.push_back({
        pos,
        Point(),
        direction,
    });
}

void Snake::draw()
{
    for (auto& part : this->snakeBody)
    {
        Graphics::Draw(
            this->_skin,
            Graphics::Property(
                this->_color
            ),
            part.pos
        );
    }
}

void Snake::erase()
{
    for(auto& part : this->snakeBody)
    {
        Graphics::Draw(
            " ",
            Graphics::Property(),
            part.pos
        );
    }
}

void Snake::move()
{
    this->erase();
    
    // move 

    this->draw();
}