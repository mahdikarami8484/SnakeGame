#pragma once

#include "core/graphics.h"
#include "core/point.h"

class Object
{
public:
    // Draw the object on the view.
    virtual void draw() = 0;

    // Erase or clear the object from the view.
    virtual void erase() = 0;

    // Move the object to a new position in the view.
    virtual void move() = 0;

    // Handles the current point of the object.
    Point CurrentPoint() const;
    void SetCurrentPoint(Point const &value);

protected:
    Point _current;
    std::string _skin;
};