#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed
{
    private:
        int value;
        static const int fraction;
    
    public:
        Fixed(void);
        Fixed(const int n);
        Fixed(const float f);
        ~Fixed(void);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream & operator << (std::ostream &out, const Fixed &f);

#endif // __FIXED_HPP__
