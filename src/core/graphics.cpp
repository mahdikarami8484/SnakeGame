#include "core/graphics.h"
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

void Graphics::SetForeground(Color const &color) {
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    ScreenInfo info = GetScreenInfo(output);

    WORD value = static_cast<WORD>(color);
    WORD attributes = info.csbi.wAttributes;
    SetConsoleTextAttribute(output, info.csbi.wAttributes);
}

void Graphics::SetBackground(const Graphics::Color &color) {
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD value = static_cast<WORD>(color) << 4;
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