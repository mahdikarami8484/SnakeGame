#include "objects/object.h"

Point Object::CurrentPoint() const {
    return _current;
}
void Object::SetCurrentPoint(Point const &value) {
    _current = value;
}