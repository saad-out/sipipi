#ifndef __POINT_HPP__
#define __POINT_HPP__

#include <iostream>
#include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;
    
    public:
        Point(void);
        Point(const float x, const float y);
        Point(const Point& other);
        Point& operator = (const Point& other);
        ~Point(void);

        float get_x(void) const;
        float get_y(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif // __POINT_HPP__
