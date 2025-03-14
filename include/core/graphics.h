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

    enum class TextAttribute {
        Normal          = 0,
        Underline       = 0x8000,
        Bright          = 0x0008,
        Dim             = 0x0002,
        Blink           = 0x0010,
        ReverseVideo    = 0x0200,
        Hidden          = 0x0800
    };

    class Property {
    public:
        Color foreground = Color::White;
        Color background = Color::Black;
        TextAttribute attribute = TextAttribute::Normal;
    };

    void EraseConsole();

    void SetForeground(Color const &color);
    void SetBackground(Color const &color);
    void SetTextAttribute(TextAttribute const &attributes);

    void SetProperty(Property const &property);

    void MoveCursor(Point const &point);
    void MoveCursor(Component const& x, Component const& y);

    void Draw(std::string const &text, Property const &property);
}

#endif