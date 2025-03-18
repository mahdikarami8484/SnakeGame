#include "core/graphics.h"
#include <windows.h>
#include <iostream>
#include <string>

Graphics::Property::Property(Color const& foreground, Color const& background)
{
    this->foreground = foreground;
    this->background = background;
}

struct ScreenInfo {
    COORD size;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
};

ScreenInfo GetScreenInfo(HANDLE output)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    ScreenInfo information;

    if (GetConsoleScreenBufferInfo(output, &csbi)) {
        int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;    
        information = {static_cast<SHORT>(width), static_cast<SHORT>(height), csbi}; 
    }

    return information;
}

Graphics::Color Graphics::GetForeground()
{
    ScreenInfo info = GetScreenInfo(GetStdHandle(STD_OUTPUT_HANDLE));
    return static_cast<Color>(info.csbi.wAttributes & 0x000F);
}
void Graphics::SetForeground(Color const &color) {
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD attributes = GetScreenInfo(output).csbi.wAttributes;

    attributes &= (0xFFF0);
    attributes |= static_cast<WORD>(color) & 0x000F;

    SetConsoleTextAttribute(output, attributes);
}


Graphics::Color Graphics::GetBackground()
{
    ScreenInfo info = GetScreenInfo(GetStdHandle(STD_OUTPUT_HANDLE));
    return static_cast<Color>(info.csbi.wAttributes & 0x00F0);
}
void Graphics::SetBackground(const Graphics::Color &color)
{
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD attributes = GetScreenInfo(output).csbi.wAttributes;

    attributes &= (0xFF0F);
    attributes |= (static_cast<WORD>(color) & 0x000F) << 4;

    SetConsoleTextAttribute(output, attributes);
}

void Graphics::SetProperty(Property const &property) {
    SetForeground(property.foreground);
    SetBackground(property.background);
}
Graphics::Property Graphics::GetProperty()
{
    return Property(GetForeground(), GetBackground());
}

void Graphics::Draw(std::string const &text, Property const &property) {
    using namespace std;

    SetProperty(property);

    cout << text;

    SetProperty(Property());

    Graphics::MoveCursor(Point());
}

void Graphics::Draw(std::string const &text, Property const &property, Point const &point)
{
    MoveCursor(point);
    Draw(text, property);
}

void Graphics::Draw(std::string const &text, Property const &property, Component const &x, Component const &y)
{
    MoveCursor(x, y);
    Draw(text, property);
}

void Graphics::MoveCursor(Point const &point)
{
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

Size Graphics::GetSize()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    return Size(GetScreenInfo(handle).size.X, GetScreenInfo(handle).size.Y);
}