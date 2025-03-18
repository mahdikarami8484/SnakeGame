#include "objects/food.h"

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