#include "include/game/object.h"

void Object::setCurrentPoint(Point const &value)
{
    _point = value;
}
Point Object::getCurrentPoint() const
{
    return _point;
}