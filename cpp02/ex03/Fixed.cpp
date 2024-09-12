#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const float EPSILON = 0.003;
// const float EPSILON = std::numeric_limits<float>::epsilon();

const int Fixed::factor = 8;

int ft_pow(int x, int y)
{
    // x^y
    int result = 1;
    for (int i = 0; i < y; i++)
        result *= x;
    return (result);
}

Fixed::Fixed(void)
{
    // std::cout << "Default constructor called" << std::endl;
    value = 0;
}

Fixed::Fixed(const int n)
{
    // std::cout << "Int constructor called" << std::endl;
    // n * 2^8
    value = (int)roundf(n * ft_pow(2, factor));
}

Fixed::Fixed(const float f)
{
    // std::cout << "Float constructor called" << std::endl;
    // f * 2^8
    value = (int)roundf(f * ft_pow(2, factor));
}

Fixed::~Fixed(void)
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
    // OR
    // this->value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
    // std::cout << "Copy assignement operator called" << std::endl;
    this->value = other.value;
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
    return ((float)value / ft_pow(2, factor));
}

int Fixed::toInt(void) const
{
    return ((int)roundf(toFloat()));
}

std::ostream & operator << (std::ostream &out, const Fixed &f)
{
    out << f.toFloat();
    return (out);
}

bool Fixed::operator == (const Fixed &other) const
{
    return (this->toFloat() == other.toFloat());
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
    float result = toFloat() + EPSILON;
    *this = Fixed(result);
    return (*this);
}

Fixed& Fixed::operator -- (void)
{
    float result = toFloat() - EPSILON;
    *this = Fixed(result);
    return (*this);
}

Fixed Fixed::operator ++ (int)
{
    Fixed copy = *this;
    float result = toFloat() + EPSILON;
    *this = Fixed(result);
    return (copy);
}

Fixed Fixed::operator -- (int)
{
    Fixed copy = *this;
    float result = toFloat() - EPSILON;
    *this = Fixed(result);
    return (copy);
}

Fixed& Fixed::min(Fixed &f1, Fixed &f2)
{
    if (f1 <= f2)
        return (f1);
    return (f2);
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2)
{
    if (f1 > f2)
        return (f1);
    return (f2);
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2)
{
    if (f1 <= f2)
        return (f1);
    return (f2);
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2)
{
    if (f1 > f2)
        return (f1);
    return (f2);
}
