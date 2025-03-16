#pragma once

#include <map>

class KeyRecognizer {
public:
    KeyRecognizer();
    void CheckForAction();

protected:
    virtual void MoveLeft() = 0;
    virtual void MoveRight() = 0;
    virtual void MoveFoward() = 0;
    virtual void MoveBackward() = 0;

private:
    enum class Action {
        MoveLeft,
        MoveRight,
        MoveFoward,
        MoveBackward
    };
    std::multimap<Action, short> _controls;
};