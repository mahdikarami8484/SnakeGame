#include "views/view.h"

void View::run() {
    this->_run = true;
}

void View::pause() {
    this->_run = false;
}

bool View::isRunning() {
    return this->_run;
}