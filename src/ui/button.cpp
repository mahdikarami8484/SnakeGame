#include "ui/button.h"

Button::Button(
    std::string text, 
    Graphics::Property property,
    Point point,
    Size size
) : Object(point) {
    
}

std::string Button::GetSkin() const {
    return this->GetText();
}

Point Button::CurrentPoint() const {
    return this->GetStartPoint();
}

void Button::SetCurrentPoint(Point const &value) {
    this->SetStartPoint(value);
}

Graphics::Color Button::GetForeground() const {
    return this->GetProperty().foreground;
}

Graphics::Color Button::GetBackground() const {
    return this->GetProperty().background;
}