#include <iostream>
#include "Point.hpp"

int main( void )
{
	Point a(0, 0), b(10, 30), c(20, 0), p(30, 15);

	if (bsp(a, b, c, p))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Outside" << std::endl;
	return (0);
}
