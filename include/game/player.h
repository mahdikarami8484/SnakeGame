#ifndef PLAYER_H
#define PLAYER_H

#include "core/Object.h"
#include <vector>

class Player : public Object
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

        std::vector<BodyPart> playerBody;

        Player(
            COORD pos, 
            COORD direction,
            COORD start_pos,
            COORD end_pos
        );
        
        ~Player();

        void draw() override;
        void erase() override;
        void move() override;
        void handler_keys() override;

};

#endif