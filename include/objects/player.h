#pragma once

#include "core/keyboard.h"
#include "object.h"
#include <vector>

class Player : public Object {
    public:
        Player(Point const &pos = Point(), Point const &direction = Point()) : Object(pos) {
            this->_direction = direction;
        }; 

    protected:
        std::string GetSkin() const override;
        Graphics::Color GetForeground() const override;
        Graphics::Color GetBackground() const override;

    protected:
        Point _lastPos = Point();    
    public:
        Point GetLastPos() const;
        void SetLastPos(Point pos);

    protected:
        Point _direction = Point();
    public:
        Point GetDirection() const;
        void SetDirection(Point pos);

};