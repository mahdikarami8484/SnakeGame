#include "core/keyboard.h"
#include "core/system.h"
#include <windows.h>

KeyRecognizer::KeyRecognizer()
{
    _controls.insert({Action::MoveFoward, VK_UP});
    _controls.insert({Action::MoveBackward, VK_DOWN});
    _controls.insert({Action::MoveLeft, VK_LEFT});
    _controls.insert({Action::MoveRight, VK_RIGHT});
}

void KeyRecognizer::CheckForAction()
{
    auto result = _controls.equal_range(Action::MoveFoward);
    for(auto i = result.first; i != result.second; ++i) {
        if(GetAsyncKeyState(i->second) & 0x8000) {
            MoveFoward();
            return;
        }
    }

    result = _controls.equal_range(Action::MoveBackward);
    for(auto i = result.first; i != result.second; ++i) {
        if(GetAsyncKeyState(i->second) & 0x8000) {
            MoveBackward();
            return;
        }
    }

    result = _controls.equal_range(Action::MoveLeft);
    for(auto i = result.first; i != result.second; ++i) {
        if(GetAsyncKeyState(i->second) & 0x8000) {
            MoveLeft();
            return;
        }
    }

    result = _controls.equal_range(Action::MoveRight);
    for(auto i = result.first; i != result.second; ++i) {
        if(GetAsyncKeyState(i->second) & 0x8000) {
            MoveRight();
            return;
        }
    }
}