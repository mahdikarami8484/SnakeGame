#pragma once

#include <cstdint>
#include <ostream>

// Defines the dimensions of the board.
using Dimension = uint8_t;

class Size {
public:
    Size();
    Size(const Size &another);
    Size(Dimension const &width, Dimension const &height);

    Size& operator=(Size const &another);

    Dimension GetWidth() const;
    void SetWidth(Dimension const &value);

    Dimension GetHeight() const;
    void SetHeight(Dimension const &value);

    size_t Area() const;

    friend std::ostream& operator<<(std::ostream &output, Size const &size);
    friend bool operator==(Size const& one, Size const& two);
    friend bool operator!=(Size const& one, Size const& two);
    friend Size operator+(Size const& one, Size const& two);
    friend Size operator-(Size const& one, Size const& two);

private:
    Dimension _width = 0;
    Dimension _height = 0;
};

std::ostream& operator<<(std::ostream &stream, Size const &size);
bool operator==(Size const& one, Size const& two);
bool operator!=(Size const& one, Size const& two);
friend Size operator+(Size const& one, Size const& two);
friend Size operator-(Size const& one, Size const& two);