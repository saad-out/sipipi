#include "Point.hpp"

float ft_fabs(float x)
{
    if (x < 0)
        return (x * (-1));
    return (x);
}

// ABC = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2
float area(Point const a, Point const b, Point const c)
{
    float x1 = a.get_x() * (b.get_y() - c.get_y());
    float x2 = b.get_x() * (c.get_y() - a.get_y());
    float x3 = c.get_x() * (a.get_y() - b.get_y());

    return (ft_fabs((x1 + x2 + x3) / 2));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float abc_area = area(a, b, c);
    float pab_area = area(point, a, b);
    float pbc_area = area(point, b, c);
    float pac_area = area(point, a, c);

    if (!pab_area || !pbc_area || !pac_area)
        return (false);
    return ((pab_area + pbc_area + pac_area) == abc_area);
}
