#include "objects/food.h"

void Food::Draw()
{
    Graphics::Draw(this->GetSkin(), Graphics::Property(GetForeground(), GetBackground()), this->_current);
}
void Food::Erase()
{
    Graphics::Draw(" ", Graphics::Property(GetForeground(), GetBackground()), this->_current);
}
std::string Food::GetSkin() const
{
    return "*";
}
Graphics::Color Food::GetForeground() const
{
    return Graphics::Color::Magenta;
}
Graphics::Color Food::GetBackground() const
{
    return Graphics::Color::Black;
}