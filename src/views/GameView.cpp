#include "views/gameview.h"

GameView::GameView(){
    this->_viewSize = Size(
        Graphics::GetSize() - Size(3, 3)
    );
    this->_viewStartPos = Point(2, 2);
}

std::string GameView::GetName() const {
    return "GameView";
}

void GameView::addWall(Point pos) {
    Block block(pos);
    block.draw();

    this->blocks.push_back(
       block
    );
}

void GameView::addWalls() {
    for (size_t i = this->_viewStartPos.GetX(); i <= this->_viewSize.GetWidth(); i++)
        this->addWall(Point(i, this->_viewStartPos.GetY()));

    for (size_t i = this->_viewStartPos.GetX(); i <= this->_viewSize.GetWidth(); i++)
        this->addWall(Point(i, this->_viewSize.GetHeight()));

    for (size_t i = this->_viewStartPos.GetY(); i <= this->_viewSize.GetHeight(); i++)
        this->addWall(Point(this->_viewStartPos.GetX(), i));

    for (size_t i = this->_viewStartPos.GetY(); i <= this->_viewSize.GetHeight(); i++)
        this->addWall(Point(this->_viewSize.GetWidth(), i));
}

void GameView::spawnFood() {
    this->food.SetCurrentPoint(
        Point(
            System::GenerateNumber(
                this->_viewStartPos.GetX() + 1, 
                this->_viewSize.GetWidth() - 1
            ),
            System::GenerateNumber(
                this->_viewStartPos.GetY() + 1, 
                this->_viewSize.GetHeight() - 1
            )
        )
    );
    
    this->food.draw();
}

void GameView::spawnSnake() {
    this->snake = Snake(
        Point(
            this->_viewSize.GetWidth() / 2,
            this->_viewSize.GetHeight() / 2
        ), 
        Point(1, 0));
    this->snake.draw();
}

void GameView::MoveUp(){
    this->snake.setDirection(Point(0, -1));
}

void GameView::MoveDown(){
    this->snake.setDirection(Point(0, 1));
}

void GameView::MoveLeft(){
    this->snake.setDirection(Point(-1, 0));
}

void GameView::MoveRight(){
    this->snake.setDirection(Point(1, 0));
}

void GameView::start() {
    this->addWalls();
    this->spawnFood();
    this->spawnSnake();

    std::thread keyActionThread([this]() {
        while (true) {
            this->CheckForAction();
        }
    });  

    keyActionThread.detach();
}

void GameView::update(){
    System::Delay(500);
    this->snake.move();
}