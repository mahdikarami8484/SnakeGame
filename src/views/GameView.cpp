#include "views/gameview.h"
#include <sstream>

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

void GameView::drawTitle()
{
    std::stringstream stream;
    stream << "Score: " << this->snake.GetScore();

    Size size = Graphics::GetSize();
    size_t center = size.GetWidth() / 2;
    Graphics::Draw(
        stream.str(),
        Graphics::Property(Graphics::Color::Red, Graphics::Color::Cyan),
        Point(center - stream.str().size() / 2, 1)
    );
}
void GameView::MoveUp()
{
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
    this->drawTitle();
    this->spawnSnake();

    std::thread keyActionThread([this]() {
        while (true) {
            this->CheckForAction();
        }
    });  

    keyActionThread.detach();
}

void GameView::checkCollisionWithFood() {
    if(this->snake.CurrentPoint() == this->food.CurrentPoint()) {
        this->snake.add();
        this->snake.SetScore(this->snake.GetScore() + 1);
        this->drawTitle();
        spawnFood();
    }
}

void GameView::checkCollisionWithWalls() {
    if(
        this->snake.CurrentPoint().GetY() >= this->_viewSize.GetHeight() ||
        this->snake.CurrentPoint().GetX() >= this->_viewSize.GetWidth() ||
        this->snake.CurrentPoint().GetX() <= this->_viewStartPos.GetX() ||
        this->snake.CurrentPoint().GetY() <= this->_viewStartPos.GetY()
    ) {
        this->pause();
    }
}

void GameView::update(){
    System::Delay(100);
    this->snake.move();
    checkCollisionWithFood();
    checkCollisionWithWalls();
}

void GameView::whenPause() {}