#include <iostream>
#include "Point.hpp"

int main( void )
{
	Point insidePoints[] = { Point(10.01, 0.01f), Point(10, 15), Point(10.f, 29.9f)};
	Point outsidePoints[] = { Point(-10.01, 0.01f), Point(20, 0), Point(10.f, 0.f)};
	Point a(0, 0), b(10, 30), c(20, 0);

	std::cout << "===> inside points: " << std::endl;
	for (int i = 0; i < 3; i++)
	{
		if (bsp(a, b, c, insidePoints[i]))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Outside" << std::endl;
	}

	std::cout << "\n===> outside points: " << std::endl;
	for (int i = 0; i < 3; i++)
	{
		if (bsp(a, b, c, outsidePoints[i]))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Outside" << std::endl;
	}

	return (0);
}
