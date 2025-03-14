#ifndef CONSOLE_H
#define CONSOLE_H

#include "point.h"

namespace Graphics {
    enum class Color {
        Black,
        Blue,
        Green,
        Cyan,
        Red,
        Magneta,
        Yellow,
        White,
        Gray,
        BrightBlue,
        BrightGreen,
        BrightCyan,
        BrightRed,
        BrightMagenta,
        BrightYellow
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