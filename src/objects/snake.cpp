#include "objects/snake.h"

Snake::Snake(
            Point pos, 
            Point direction
) : Object(pos)
{
    this->snakeBody.push_back({
        pos,
        Point(),
        direction,
    });
}

void Snake::draw()
{
    const std::string skin = this->GetSkin();
    const Graphics::Color color = this->GetForeground();
    for (auto& part : this->snakeBody)
    {
        Graphics::Draw(
            skin,
            Graphics::Property(
                color
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
            this->GetSpaces(),
            Graphics::Property(),
            part.pos
        );
    }
}

void Snake::move()
{
    this->erase();
    
    int counter = 0;
    for(auto& part : this->snakeBody)
    {
        part.last_pos = part.pos;

        if(counter)
        {
            part.pos = this->snakeBody[counter-1].last_pos;  
            continue;
        }

        part.pos += part.direction;
        counter++;
    }

    this->draw();
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
