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
        ~Fixed(void);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif // __FIXED_HPP__
