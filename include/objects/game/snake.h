#ifndef PLAYER_H
#define PLAYER_H

#include "core/object.h"
#include <vector>

class Snake : public Object
{
    public: 
        
        std::string skin = "o";

        struct BodyPart {
            COORD pos;
            COORD last_pos;
            COORD direction;
            COORD start_pos;
            COORD end_pos;
        };

        std::vector<BodyPart> snakeBody;

        Snake(
            COORD pos, 
            COORD direction,
            COORD start_pos,
            COORD end_pos
        );
        
        ~Snake();

        void draw() override;
        void erase() override;
        void move() override;
        void handler_keys() override;
};

#endif