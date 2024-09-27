#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	{
		std::cout << "Scope 1:" << std::endl;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << std::endl;
	}

	{
		std::cout << "Scope 2:" << std::endl;
		Fixed a(5);
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << a + 3.4f << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "Scope 3:" << std::endl;
		Fixed a(-10.5f);
		Fixed b(10.5f);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << "\n";
		std::cout << "Max is: " << Fixed::max( a, b ) << std::endl;
		std::cout << "Min is: " << Fixed::min( a, b ) << std::endl;

		std::cout << a + b << std::endl;
		std::cout << a - b << std::endl;
		std::cout << a / b << std::endl;
		std::cout << a * b << std::endl;

		std::cout << (a > b) << std::endl;
		std::cout << (a < b) << std::endl;
		std::cout << (a >= b) << std::endl;
		std::cout << (a <= b) << std::endl;
		std::cout << (a == b) << std::endl;
		std::cout << (a != b) << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "Scope 4 (imprecision): " << std::endl;
		Fixed a(-29.9f);
		Fixed b(-29.8984f);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << (a == b) << std::endl;
		std::cout << a - b << std::endl;
	}
	return 0;
}
