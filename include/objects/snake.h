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
        virtual void draw() override;
        virtual void erase() override;

        void add();
        void move();

        void setDirection(Point const &direction);

        size_t GetScore() const;
        void SetScore(size_t value);

    private: 
        std::vector<Player> snake;
        size_t _score = 0;
};