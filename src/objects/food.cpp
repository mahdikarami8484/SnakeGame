#include "objects/food.h"

Food::Food(Point const &pos)
{
    this->SetCurrentPoint(pos);
    this->draw();
}

void Food::draw()
{
    Graphics::Draw(
        this->GetSkin(),
        Graphics::Property(this->GetForeground()),
        this->CurrentPoint()
    );
}

void Food::erase()
{
    Graphics::Draw(
        this->GetSpaces(),
        Graphics::Property(),
        this->CurrentPoint()
    );
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