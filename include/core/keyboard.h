#pragma once

#include <map>

class KeyRecognizer {
public:
    KeyRecognizer();
    void CheckForAction();

protected:
    virtual void MoveLeft() = 0;
    virtual void MoveRight() = 0;
    virtual void MoveUp() = 0;
    virtual void MoveDown() = 0;

private:
    enum class Action {
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown
    };
    std::multimap<Action, short> _controls;
};