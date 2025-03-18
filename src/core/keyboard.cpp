#include "core/keyboard.h"
#include "core/system.h"
#include <windows.h>

KeyRecognizer::KeyRecognizer()
{
    _controls.insert({Action::MoveUp, VK_UP});
    _controls.insert({Action::MoveDown, VK_DOWN});
    _controls.insert({Action::MoveLeft, VK_LEFT});
    _controls.insert({Action::MoveRight, VK_RIGHT});
}

void KeyRecognizer::CheckForAction()
{
    auto result = _controls.equal_range(Action::MoveUp);
    for(auto i = result.first; i != result.second; ++i) {
        if(GetAsyncKeyState(i->second) & 0x8000) {
            MoveUp();
            return;
        }
    }

    result = _controls.equal_range(Action::MoveDown);
    for(auto i = result.first; i != result.second; ++i) {
        if(GetAsyncKeyState(i->second) & 0x8000) {
            MoveDown();
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