#include "objects/block.h"

Block::Block(Point pos) : Object(pos) {}

void Block::draw(){
    Graphics::Draw(
        this->GetSkin(),
        Graphics::Property(this->GetForeground()),
        this->CurrentPoint()
    );
}

void Block::erase(){
    Graphics::Draw(
        this->GetSpaces(),
        Graphics::Property(),
        this->CurrentPoint()
    );
}


std::string Block::GetSkin() const {
    return "#";
}

Graphics::Color Block::GetForeground() const {
    return Graphics::Color::BrightYellow;
}