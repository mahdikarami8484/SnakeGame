#include "views/gameview.h"

GameView::GameView() {
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

void GameView::start() {
    this->addWalls();
}

void GameView::update(){

}