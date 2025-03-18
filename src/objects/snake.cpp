#include "objects/snake.h"

Snake::Snake(Point const &pos, Point const &direction) : Object(pos) {
    this->snake.push_back(Player(pos, direction));
}

void Snake::add() {
    this->snake.push_back(
        Player(this->snake.back().GetLastPos())
    );
}

void Snake::draw() {
    for(auto& part : this->snake) {
        part.erase();
        part.draw();
    }
}

void Snake::erase() {
    for(auto& part : this->snake) {
        part.erase();
    }
}