#ifndef CONSOLE_H
#define CONSOLE_H

#include "point.h"

namespace Graphics {
    class Property  {
    public:
        Color foreground;
        Color background;
        Property(Color const& foreground = Color::White, Color const& background = Color::Black);
    };

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

    void EraseConsole();

    Color GetForeground();
    void SetForeground(Color const &color);

    Color GetBackground();
    void SetBackground(Color const &color);

    Property GetProperty();
    void SetProperty(Property const &property);

    void MoveCursor(Point const &point);
    void MoveCursor(Component const& x, Component const& y);

    void Draw(std::string const &text, Property const &property);
}

#endif