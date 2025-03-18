#include "core/size.h"

Size::Size() {}
Size::Size(const Size &another) {
    *this = another;
}

Size::Size(Dimension const &width, Dimension const &height) : Size() {
    _width = width;
    _height = height;
}

Size &Size::operator=(Size const &another) {
    _width = another._width;
    _height = another._height;
    return *this;
}

Dimension Size::GetWidth() const {
    return _width;
}

void Size::SetWidth(Dimension const &value) {
    _width = value;
}

Dimension Size::GetHeight() const {
    return _height;
}

void Size::SetHeight(Dimension const &value) {
    _height = value;
}

size_t Size::Area() const {
    return _width * _height;
}

bool operator==(Size const& one, Size const& two) {
    return (one._width == two._width) && (one._height == two._height);
}
bool operator!=(Size const& one, Size const& two) {
    return !(one == two);
}

Size operator+(Size const& one, Size const& two)
{
    return Size(one.GetWidth() + two.GetWidth(), one.GetHeight() + two.GetHeight());
}

Size operator-(Size const& one, Size const& two)
{
    return Size(one.GetWidth() - two.GetWidth(), one.GetHeight() - two.GetHeight());
}