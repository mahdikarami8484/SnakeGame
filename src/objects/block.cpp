#include "objects/block.h"

std::string Block::GetSkin() const {
    return "#";
}

Graphics::Color Block::GetForeground() const {
    return Graphics::Color::BrightYellow;
}

Graphics::Color Block::GetBackground() const {
    return Graphics::Color::Black;
}