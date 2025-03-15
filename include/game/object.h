#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
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

    // Handles keyboard input and processes key events.
    virtual void handler_keys() = 0;

    // Handles the current point of the object.
    inline Point currentPoint() const {
        return _current;
    }
    inline Point setCurrentPoint(Point const &value) {
        _current = value;
    }

protected:
    Point _current;
    std::string _skin;
};

#endif