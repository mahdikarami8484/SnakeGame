#ifndef CONSOLE_H
#define CONSOLE_H

#include "point.h"

namespace Graphics {
    enum class Color {
        Black       = 0x0000,
        Gray        = 0x0008,
        Red         = 0x0004,
        Green       = 0x0002,
        Blue        = 0x0001,
        Cyan            = Green | Blue,
        Yellow          = Green | Red,
        Magenta         = Blue | Red,
        BrightRed       = Red | Gray,
        BrightCyan      = Cyan | Gray,
        BrightBlue      = Blue | Gray,
        BrightGreen     = Green | Gray,
        BrightYellow    = Yellow | Gray,
        BrightMagenta   = Magenta | Gray,
        White           = Red | Green | Blue
    };

    class Property {
    public:
        Color foreground = Color::White;
        Color background = Color::Black;
    };

    void EraseConsole();

    void SetForeground(Color const &color);
    void SetBackground(Color const &color);

    void SetProperty(Property const &property);

    void MoveCursor(Point const &point);
    void MoveCursor(Component const& x, Component const& y);

    void Draw(std::string const &text, Property const &property);
}

#endif