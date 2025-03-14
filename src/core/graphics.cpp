#include "include/core/graphics.h"
#include <windows.h>
#include <iostream>
#include <string>

struct ScreenInfo {
    COORD size;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
};
ScreenInfo GetScreenInfo(HANDLE output)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    ScreenInfo information;

    if (GetConsoleScreenBufferInfo(handle, &csbi)) {
        int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;    
        information = {static_cast<SHORT>(width), static_cast<SHORT>(height), csbi}; 
    }

    return information;
}
WORD ToForeground(const Graphics::Color &color) {
    switch(color) {
        case Graphics::Color::Black: {
            return 0;
        }

        case Graphics::Color::Gray: {
            return FOREGROUND_INTENSITY;
        }

        case Graphics::Color::Blue: {
            return FOREGROUND_BLUE;
        }

        case Graphics::Color::BrightBlue: {
            return FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        }

        case Graphics::Color::Green: {
            return FOREGROUND_GREEN;
        }

        case Graphics::Color::BrightGreen: {
            return FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        }

        case Graphics::Color::Red: {
            return FOREGROUND_RED;
        }

        case Graphics::Color::BrightRed: {
            return FOREGROUND_RED | FOREGROUND_INTENSITY;
        }

        case Graphics::Color::Cyan: {
            return FOREGROUND_BLUE | FOREGROUND_GREEN;
        }

        case Graphics::Color::BrightCyan: {
            return FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        }

        case Graphics::Color::Magenta: {
            return FOREGROUND_BLUE | FOREGROUND_RED;
        }

        case Graphics::Color::BrightMagenta: {
            return FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;
        }

        case Graphics::Color::Yellow: {
            return FOREGROUND_GREEN | FOREGROUND_RED;
        }

        case Graphics::Color::BrightYellow: {
            return FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
        }

        case Graphics::Color::White: {
            return FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
        }

        default: {
            return 0;
        }
    }
}
WORD ToBackground(const Graphics::Color &color) {
    return ToForeground(color) << 4;
}

void Graphics::SetForeground(Color const &color) {
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    ScreenInfo info = GetScreenInfo(output);

    WORD value = ToForeground(color);
    WORD attributes = info.csbi.wAttributes;
    SetConsoleTextAttribute(output, info.csbi.wAttributes);
}

void Graphics::SetBackground(const Graphics::Color &color) {
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

    WORD value = ToBackground(color);
    SetConsoleTextAttribute(output, value);
}

void Graphics::SetTextAttribute(TextAttribute const &attribute) {
        HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Graphics::SetProperty(Property const &property) {
    SetForeground(property.foreground);
    SetBackground(property.background);
    SetTextAttribute(property.attribute);
}

void Graphics::Draw(std::string const &text, Property const &property) {
    using namespace std;

    // Updates the color of the terminal.
    SetProperty(property);

    // Prints the string.
    cout << text;

    // Resets the property
    SetProperty(Property());
}

void Graphics::MoveCursor(Point const &point) {
    COORD coord;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coord.X = point.GetX();
    coord.Y = point.GetY();
    SetConsoleCursorPosition(handle, coord);
}

void Graphics::MoveCursor(Component const &x, Component const &y)
{
    MoveCursor(Point(x, y));
}

void Graphics::EraseConsole()
{
    DWORD dwWritten;
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    ScreenInfo info = GetScreenInfo(output);
    FillConsoleOutputCharacter(output, ' ', info.size.X * info.size.Y, {0, 0}, &dwWritten);
    FillConsoleOutputAttribute(output,  info.csbi.wAttributes, info.size.X * info.size.Y, {0, 0},  &dwWritten);
    MoveCursor(Point(0, 0));
}