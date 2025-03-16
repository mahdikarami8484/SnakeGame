#pragma once

#include "core/keyboard.h"
#include "object.h"
#include <vector>

class Snake : public Object, KeyRecognizer
{
public:
    struct BodyPart {
        Point pos;
        Point last_pos;
        Point direction;
    };

    std::vector<BodyPart> snakeBody;

    Snake(
        Point pos,
        Point direction
    );
        
    ~Snake();

    void draw() override;
    void erase() override;
    void move() override;

protected:
    std::string GetSkin() const override;

private:
    Graphics::Color _color = Graphics::Color::BrightGreen;
    Graphics::Color _bg_color = Graphics::Color::Black;
};