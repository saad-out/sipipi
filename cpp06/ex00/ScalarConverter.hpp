#ifndef __SCALARCONVERTER__
#define __SCALARCONVERTER__

#include <iostream>

class ScalarConverter
{
    public:
        static void convert(std::string str);
        static void display(char c);
        static void display(int n);
        static void display(float n);
        static void display(double n);
        static void display(std::string &str);
};

#endif // __SCALARCONVERTER__
