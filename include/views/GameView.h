#pragma once

#include "views/view.h"


class GameView : public View 
{
        public:
            void start() override;
            
            void update() override;

            std::string GetName() const override;
};