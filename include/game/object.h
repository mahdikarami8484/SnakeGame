#ifndef OBJECT_H
#define OBJECT_H

#include "include/core/point.h"

class Object
{
    void setCurrentPoint(Point const &value);
    Point getCurrentPoint() const;
    virtual void draw() = 0;

protected:
    Point _point;
};

#endif
