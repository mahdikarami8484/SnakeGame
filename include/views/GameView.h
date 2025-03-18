#pragma once

#include "views/view.h"
#include "objects/block.h"

class GameView : public View 
{
        public:
            GameView();

        public:
            void start() override;
            
            void update() override;

            std::string GetName() const override;
        
        private:
            std::vector<Block> blocks;
            Size _viewSize;
            Point _viewStartPos;

        private: 
            void addWalls();
            void addWall(Point pos);
};
