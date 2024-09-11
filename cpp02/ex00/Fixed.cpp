#include "Fixed.hpp"

const int Fixed::factor = 8;

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
    // OR
    // this->value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignement constructor called" << std::endl;
    this->value = other.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}
