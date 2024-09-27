#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::fraction = 8;

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    // n * 2^8
    value = n << fraction;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    // f * 2^8
    value = (int)roundf(f * (1 << fraction));
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
    std::cout << "Copy assignement operator called" << std::endl;
    this->value = other.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)value / (1 << fraction));
}

int Fixed::toInt(void) const
{
    return (value >> fraction);
}

std::ostream & operator << (std::ostream &out, const Fixed &f)
{
    out << f.toFloat();
    return (out);
}

bool Fixed::operator == (const Fixed &other) const
{
    return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator != (const Fixed &other) const
{
    return (!(*this == other));
}

bool Fixed::operator > (const Fixed &other) const
{
    return (this->toFloat() > other.toFloat());
}

bool Fixed::operator >= (const Fixed &other) const
{
    return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator < (const Fixed &other) const
{
    return (this->toFloat() < other.toFloat());
}

bool Fixed::operator <= (const Fixed &other) const
{
    return (this->toFloat() <= other.toFloat());
}

Fixed Fixed::operator + (const Fixed &other) const
{
    float result = this->toFloat() + other.toFloat();
    return (Fixed(result));
}

Fixed Fixed::operator - (const Fixed &other) const
{
    float result = this->toFloat() - other.toFloat();
    return (Fixed(result));
}

Fixed Fixed::operator / (const Fixed &other) const
{
    float result = this->toFloat() / other.toFloat();
    return (Fixed(result));
}

Fixed Fixed::operator * (const Fixed &other) const
{
    float result = this->toFloat() * other.toFloat(); // could overflow ?
    return (Fixed(result));
}

Fixed& Fixed::operator ++ (void)
{
    this->value++;
    return (*this);
}

Fixed& Fixed::operator -- (void)
{
    this->value--;
    return (*this);
}

Fixed Fixed::operator ++ (int)
{
    Fixed copy = *this;
    this->value++;
    return (copy);
}

Fixed Fixed::operator -- (int)
{
    Fixed copy = *this;
    this->value--;
    return (copy);
}

Fixed& Fixed::min(Fixed &f1, Fixed &f2)
{
    return (f1 <= f2 ? f1 : f2);
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2)
{
    return (f1 > f2 ? f1 : f2);
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2)
{
    return (f1 <= f2 ? f1 : f2);
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2)
{
    return (f1 > f2 ? f1 : f2);
}
