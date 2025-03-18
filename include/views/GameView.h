#pragma once

#include "core/keyboard.h"
#include "views/view.h"
#include "objects/block.h"
#include "objects/food.h"
#include "objects/snake.h"
#include <thread>

class GameView : public View, public KeyRecognizer 
{
public:
    GameView();
    ~GameView();

    void start() override;
    void update() override;
    void whenPause() override;
    std::string GetName() const override;
            
protected:
    virtual void MoveUp() override;
    virtual void MoveDown() override;
    virtual void MoveLeft() override;
    virtual void MoveRight() override;

private:
    void addWalls();
    void spawnFood();
    void drawTitle();
    void spawnSnake();
    void addWall(Point pos);
    void checkCollisionWithFood();
    void checkCollisionWithWalls();

private:
    Food food;
    Snake snake;
    Size _viewSize;
    bool running = true;
    Point _viewStartPos;
    std::vector<Block> blocks;
    std::thread controlThread;
};
