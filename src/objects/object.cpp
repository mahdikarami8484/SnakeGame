#include "objects/object.h"

Point Object::CurrentPoint() const {
    return _current;
}
void Object::SetCurrentPoint(Point const &value) {
    this->Erase();
    _current = value;
    this->Draw();
}

void Object::Move() {}