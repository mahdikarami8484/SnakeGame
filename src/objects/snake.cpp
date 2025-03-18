#include "objects/snake.h"
#include <iostream>

Snake::Snake(Point const &pos, Point const &direction) : Object(pos) {
    this->snake.push_back(Player(pos, direction));
}

Point Snake::CurrentPoint() const {
    return this->snake.front().CurrentPoint();
}

void Snake::add() {
    this->snake.push_back(
        Player(this->snake.back().GetLastPos())
    );
}

void Snake::draw() {
    for(auto& part : this->snake) {
        part.draw();
    }
}

void Snake::erase() {
    for(auto& part : this->snake) {
        part.erase();
    }
}

void Snake::move() {
    this->erase();
    
    int count = 0;
    for(auto& part : this->snake){
        
        part.SetLastPos(part.CurrentPoint());

        if(count == 0){
            part.SetCurrentPoint(
                part.CurrentPoint() + part.GetDirection()
            );
            
            
        }else
            part.SetCurrentPoint(
                this->snake[count-1].GetLastPos()
            );
        
        count++;
    }

    //this->SetCurrentPoint(this->snake.front().CurrentPoint());
    this->draw();
}

void Snake::setDirection(Point const &direction) {
    this->snake[0].SetDirection(direction);
}

size_t Snake::GetScore() const
{
    return _score;
}
void Snake::SetScore(size_t value)
{
    _score = value;
}