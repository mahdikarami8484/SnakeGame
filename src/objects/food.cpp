#include "objects/food.h"

std::string Food::GetSkin() const
{
    return "*";
}
Graphics::Color Food::GetForeground() const
{
    return Graphics::Color::BrightMagenta;
}
Graphics::Color Food::GetBackground() const
{
    return Graphics::Color::Black;
}