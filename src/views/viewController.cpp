#include "views/viewController.h"

#include "views/GameView.h"

ViewController::ViewController() {

    this->_viewList.addView(GameView().GetName(), std::make_shared<GameView>());
}

void ViewController::ViewList::addView(std::string const &name, std::shared_ptr<View> view) {
    this->views.push_back(view);
    this->name_map[name] = view;
}

std::shared_ptr<View> 
    ViewController::ViewList::GetViewByName(std::string const &name) {
        if(this->name_map.find(name) == name_map.end()) return nullptr;
        return this->name_map[name];
}

ViewController::ViewList ViewController::GetViewList() const {
    return this->_viewList;
}

void ViewController::SetCurrentView(std::shared_ptr<View> view) {
    this->_currentView = view;
}

std::shared_ptr<View> ViewController::GetCurrentView() const {
    return this->_currentView;
}

bool ViewController::isViewLoaded() const {
    return this->_viewLoaded;
}

void ViewController::load(std::shared_ptr<View> view) {
    this->unLoad();

    this->SetCurrentView(view);

    std::thread viewThread([this]() {
        this->GetCurrentView()->start();

        this->_viewLoaded = true;

        while (this->isViewLoaded()) {
            this->GetCurrentView()->update();
        }
    });  
    viewThread.detach();
}

void ViewController::unLoad() {
    Graphics::EraseConsole();
    
    this->_viewLoaded = false;
    this->SetCurrentView(nullptr);
}