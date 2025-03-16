#include "objects/object.h"

Point Object::GetPosition() const {
    return _current;
}
void Object::SetPosition(Point const &value) {
    this->Erase();
    _current = value;
    this->Draw();
}

void Object::Move() {}