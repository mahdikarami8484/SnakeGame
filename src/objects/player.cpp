#include "objects/Player.h"

Point Player::GetLastPos() const {
    return this->_lastPos;
}

void Player::SetLastPos(Point pos) {
    this->_lastPos = pos;
}

Point Player::GetDirection() const {
    return this->_direction;
}

void Player::SetDirection(Point pos) {
    this->_direction = pos;
}

std::string Player::GetSkin() const
{
    return "o";
}
Graphics::Color Player::GetForeground() const
{
    return Graphics::Color::BrightGreen;
}

Graphics::Color Player::GetBackground() const
{
    return Graphics::Color::Black;
}
