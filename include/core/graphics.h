#pragma once

#include "point.h"
#include "size.h"

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

    class Property  {
    public:
        Color foreground;
        Color background;
        Property(Color const& foreground = Color::White, Color const& background = Color::Black);
    };

    Size GetSize();
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