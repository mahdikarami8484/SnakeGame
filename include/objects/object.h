#pragma once

#include "core/graphics.h"
#include "core/point.h"

class Object
{
public:
    virtual void Draw() = 0;
    virtual void Move() = 0;
    virtual void Erase() = 0;

    Point CurrentPoint() const;
    void SetCurrentPoint(Point const &value);

protected:
    virtual std::string GetSkin() const = 0;
    virtual Graphics::Color GetForeground() const = 0;
    virtual Graphics::Color GetBackground() const = 0;

protected:
    Point _current;
};