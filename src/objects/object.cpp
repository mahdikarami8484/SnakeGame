#include "objects/object.h"

Object::Object(Point const &pos)
{
    this->SetCurrentPoint(pos);
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