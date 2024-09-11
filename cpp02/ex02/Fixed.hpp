#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed
{
    private:
        int value;
        static const int factor;
    
    public:
        Fixed(void);
        Fixed(const int n);
        Fixed(const float f);
        ~Fixed(void);
        Fixed(const Fixed& other);

        Fixed& operator = (const Fixed& other);
        bool operator == (const Fixed& other) const;
        bool operator != (const Fixed& other) const;
        bool operator > (const Fixed& other) const;
        bool operator >= (const Fixed& other) const;
        bool operator < (const Fixed& other) const ;
        bool operator <= (const Fixed& other) const;
        Fixed operator + (const Fixed& other) const;
        Fixed operator - (const Fixed& other) const;
        Fixed operator / (const Fixed& other) const;
        Fixed operator * (const Fixed& other) const;
        Fixed& operator ++ (void);
        Fixed& operator -- (void);
        Fixed operator ++ (int);
        Fixed operator -- (int);

        static Fixed& min(Fixed &f1, Fixed &f2);
        static Fixed& max(Fixed &f1, Fixed &f2);
        static const Fixed& min(const Fixed &f1, const Fixed &f2);
        static const Fixed& max(const Fixed &f1, const Fixed &f2);


        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        friend std::ostream & operator << (std::ostream &out, const Fixed &f);
};

#endif // __FIXED_HPP__
