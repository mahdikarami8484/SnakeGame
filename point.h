#pragma once

#include <cstdint>
#include <istream>
#include <ostream>
#include <exception>

using Component = int64_t;

// Defines the core functionality of a point.
class Point
{
private:
    Component _x = 0;
    Component _y = 0;

private:
    friend Point operator+(Point const& one, Point const& two);
    friend Point operator-(Point const& one, Point const& two);
    friend bool operator==(Point const& one, Point const& two);
    friend bool operator!=(Point const& one, Point const& two);
    friend std::ostream& operator<<(std::ostream& output, Point const& point);

public:
    Point();
    Point(Point const& _object);
    Point(Component const& _x, Component const& _y);

    Point& operator=(Point const& _object);

    Component GetX() const;
    Component& ReferX();

    Component GetY() const;
    Component& ReferY();

    void Traspose();
    void SetX(Component const& _x);
    void SetY(Component const& _y);

    void MoveTop();
    void MoveTop(Component const& _factor);

    void MoveLeft();
    void MoveLeft(Component const& _factor);

    void MoveRight();
    void MoveRight(Component const& _factor);

    void MoveBottom();
    void MoveBottom(Component const& _factor);

    void MoveTopLeft();
    void MoveTopLeft(Component const& _factor);

    void MoveTopRight();
    void MoveTopRight(Component const& _factor);

    void MoveBottomLeft();
    void MoveBottomLeft(Component const& _factor);

    void MoveBottomRight();
    void MoveBottomRight(Component const& _factor);

    Point& operator+=(Point const& point);
    Point& operator-=(Point const& point);

public:
    static Point Transposed(Point const& point);

};

Point operator+(Point const& one, Point const& two);
Point operator-(Point const& one, Point const& two);

bool operator==(Point const& one, Point const& two);
bool operator!=(Point const& one, Point const& two);
std::ostream& operator<<(std::ostream& output, Point const& point);

#include <vector>
using PointList = std::vector<Point>;
