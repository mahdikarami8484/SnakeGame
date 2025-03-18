#pragma once

#include "views/view.h"
#include "objects/block.h"
#include "objects/food.h"
#include "objects/snake.h"

class GameView : public View 
{
        public:
            GameView();

        public:
            void start() override;
            
            void update() override;

            std::string GetName() const override;
        
        private:
            Size _viewSize;
            Point _viewStartPos;

        // Block Object 
        private:
            std::vector<Block> blocks;           
        private: 
            void addWalls();
            void addWall(Point pos);
            
        // Food Object
        private:
            Food food;
        private:
            void spawnFood();

        // Snake Object
        private:
            Snake snake;
        private:
            void spawnSnake();

};
