#include "core/point.h"

Point::Point()
{
    this->_x = 0;
    this->_y = 0;
}

Point::Point(Point const& _object) : Point()
{
    this->_x = _object._x;
    this->_y = _object._y;
}

Point::Point(Component const& _x, Component const& _y)
{
    this->_x = _x;
    this->_y = _y;
}

Point& Point::operator=(Point const& _object)
{
    this->_x = _object._x;
    this->_y = _object._y;
    return *this;
}

Component Point::GetX() const
{
    return this->_x;
}

Component& Point::ReferX()
{
    return this->_x;
}

void Point::Traspose()
{
    Component _temp = this->_x;
    this->_x = this->_y;
    this->_y = _temp;
}

void Point::SetX(Component const& _x)
{
    this->_x = _x;
}

Component Point::GetY() const
{
    return this->_y;
}

Component& Point::ReferY()
{
    return this->_y;
}

void Point::SetY(Component const& _y)
{
    this->_y = _y;
}

void Point::MoveTop()
{
    MoveTop(1);
}
void Point::MoveTop(Component const& _factor)
{
    this->_y -= _factor;
}

void Point::MoveLeft()
{
    MoveLeft(1);
}

void Point::MoveLeft(Component const& _factor)
{
    this->_x -= _factor;
}

void Point::MoveRight()
{
    MoveRight(1);
}

void Point::MoveRight(Component const& _factor)
{
    this->_x += _factor;
}

void Point::MoveBottom()
{
    MoveBottom(1);
}

void Point::MoveBottom(Component const& _factor)
{
    this->_y += _factor;
}

void Point::MoveTopLeft()
{
    MoveTopLeft(1);
}

void Point::MoveTopLeft(Component const& _factor)
{
    MoveTop(_factor);
    MoveLeft(_factor);
}

void Point::MoveTopRight()
{
    MoveTopRight(1);
}

void Point::MoveTopRight(Component const& _factor)
{
    MoveTop(_factor);
    MoveRight(_factor);
}

void Point::MoveBottomLeft()
{
    MoveBottomLeft(1);
}

void Point::MoveBottomLeft(Component const& _factor)
{
    MoveBottom(_factor);
    MoveLeft(_factor);
}

void Point::MoveBottomRight()
{
    MoveBottomRight(1);
}

void Point::MoveBottomRight(Component const& _factor)
{
    MoveBottom(_factor);
    MoveRight(_factor);
}

Point& Point::operator+=(Point const& point)
{
    this->_x += point._x;
    this->_y += point._y;
    return *this;
}

Point& Point::operator-=(Point const& point)
{
    this->_x -= point._x;
    this->_y -= point._y;
    return *this;
}

Point Point::Transposed(Point const& point)
{
    return Point(point._y, point._x);
}

Point operator+(Point const& one, Point const& two)
{
    return Point(one._x + two._x, one._y + two._y);
}

Point operator-(Point const& one, Point const& two)
{
    return Point(one._x - two._x, one._y - two._y);
}

bool operator==(Point const& one, Point const& two)
{
    return (one._x == two._x) && (one._y == two._y);
}

bool operator!=(Point const& one, Point const& two)
{
    return !(one == two);
}
std::ostream &operator<<(std::ostream &output, Point const &point)
{
    output << '(' << point._x << ',' << ' ' << point._y << ')';
    return output;
}