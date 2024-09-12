#include "Point.hpp"

Point::Point(void) : x(Fixed(0.0f)), y(Fixed(0.0f)) {}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator = (const Point& other)
{
    (void)other;
    return (*this);
}

Point::~Point(void) {}

float Point::get_x(void) const
{
    return (x.toFloat());
}

float Point::get_y(void) const
{
    return (y.toFloat());
}
