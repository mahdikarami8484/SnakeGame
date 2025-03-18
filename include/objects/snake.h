#pragma once

#include "core/keyboard.h"
#include "object.h"
#include <vector>

class Snake : public Object {
    public:
        Snake(Point const &pos) : Object(pos) {}; 

    protected:
        std::string GetSkin() const override;
        Graphics::Color GetForeground() const override;
        Graphics::Color GetBackground() const override;

    protected:
        Point _lastPos;    
    public:
        Point GetLastPos() const;
        void SetLastPos(Point pos);

    protected:
        Point _direction;
    public:
        Point GetDirection() const;
        void SetDirection(Point pos);

};