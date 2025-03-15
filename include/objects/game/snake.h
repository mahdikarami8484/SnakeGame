#pragma once

#include "core/object.h"
#include <vector>

class Snake : public Object
{
    public: 
        
        std::string skin = "o";

        struct BodyPart {
            Point pos;
            Point last_pos;
            Point direction;
            Point start_pos;
            Point end_pos;
        };

        std::vector<BodyPart> snakeBody;

        Snake(
            Point pos, 
            Point direction,
            Point start_pos,
            Point end_pos
        );
        
        ~Snake();

        void draw() override;
        void erase() override;
        void move() override;
        void handler_keys() override;
};