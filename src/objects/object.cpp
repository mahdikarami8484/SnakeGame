#include "objects/object.h"

Object::Object(Point const &pos)
{
    this->SetCurrentPoint(pos);
}

void Object::draw()
{
    this->erase();

    Graphics::Draw(
        this->GetSkin(),
        Graphics::Property(this->GetForeground()),
        this->CurrentPoint()
    );
}

void Object::erase()
{
    Graphics::Draw(
        this->GetSpaces(),
        Graphics::Property(),
        this->CurrentPoint()
    );
}

Point Object::CurrentPoint() const {
    return _current;
}
void Object::SetCurrentPoint(Point const &value) {
    _current = value;
}

std::string Object::GetSpaces() const {
    std::string spaces = "";

    for (size_t i = 0; i < this->GetSkin().size(); i++)
    {
        spaces += " ";    
    }

    return spaces;
}