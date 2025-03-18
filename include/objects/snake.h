#pragma once

#include "core/keyboard.h"
#include "object.h"
#include "player.h"
#include <vector>

class Snake : public Object {
    public:
        Snake(Point const &pos = Point(), Point const &direction = Point(1, 0));

    protected:
        std::string GetSkin() const override { return ""; };
        Graphics::Color GetForeground() const override { return Graphics::Color::Black; };
        Graphics::Color GetBackground() const override { return Graphics::Color::Black; };

    public:
        void draw();
        void erase();

        void add();

    private: 
        std::vector<Player> snake;
        
        void move();

};