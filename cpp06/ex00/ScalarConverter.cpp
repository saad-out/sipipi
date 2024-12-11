#include "ScalarConverter.hpp"
#include <string>
#include <sstream>
#include <limits>

bool isChar(std::string &str)
{
    if (str.length() != 1)
        return (false);
    char c = str[0];
    if (c < 33 || (c >= '0' && c <= '9') || c > 126)
        return (false);
    return (true);
}

bool isInt(std::string &str)
{
    if (str.length() == 0)
        return (false);
    size_t i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (i < str.length() && (str[i] >= '0' && str[i] <= '9'))
        i++;
    return (i == str.length());
}

bool isDoubleLiteral(std::string &str)
{
    return (str == "-inf" || str == "+inf" || str == "nan");
}

bool isDouble(std::string &str)
{
    if (str.length() < 2)
        return (false);
    size_t i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;

    // handle "+. OR -."
    if (i > 0 && str[i] == '.' && i == (str.length() - 1))
        return (false);

    bool isPoint = false;
    while (i < str.length())
    {
        if (str[i] == '.' && !isPoint)
            isPoint = true;
        else if (str[i] < '0' || str[i] > '9')
            return (false);
        i++;
    }
    return (isPoint && i == str.length());
}

bool isFloatLiteral(std::string &str)
{
    return (str == "-inff" || str == "+inff" || str == "nanf");
}

bool isFloat(std::string &str)
{
    std::string tmp = str.substr(0, str.length() - 1);
    return (isDouble(tmp) && str[str.length() - 1] == 'f');
}

void display(char c)
{
    std::cout << "=====> character is: " << c << std::endl;
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void display(int n)
{
    std::cout << "=====> number is: " << n << std::endl;
    std::cout << "char: ";
    if (n < 33 || (n >= '0' && n <= '9') || n > 126)
        std::cout << "non displayable" << std::endl;
    else
         std::cout << static_cast<char>(n) << std::endl;
    std::cout << "int: " << n << std::endl;
    std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

void display(float n)
{
    std::cout << "=====> float is: " << n << std::endl;
    std::cout << "char: ";
    if (n < 33 || (n >= '0' && n <= '9') || n > 126)
        std::cout << "non displayable" << std::endl;
    else
         std::cout << static_cast<char>(n) << std::endl;
    std::cout << "int: " << static_cast<int>(n) << std::endl;
    std::cout << "float: " << n;
    if (n == static_cast<int>(n))
        std::cout << ".0";
    std::cout << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(n) << std::endl;
    if (n == static_cast<int>(n))
        std::cout << ".0";
}

void display(double n)
{
    std::cout << "=====> double is: " << n << std::endl;
    std::cout << "char: ";
    if (n < 33 || (n >= '0' && n <= '9') || n > 126)
        std::cout << "non displayable" << std::endl;
    else
         std::cout << static_cast<char>(n) << std::endl;
    std::cout << "int: " << static_cast<int>(n) << std::endl;
    std::cout << "float: " << static_cast<float>(n);
    if (n == static_cast<int>(n))
        std::cout << ".0";
    std::cout << "f" << std::endl;
    std::cout << "double: " << n;
    if (n == static_cast<int>(n))
        std::cout << ".0";
    std::cout << std::endl;
}

void typecast_str(std::string &str, std::string type)
{
    if (type == "char")
        return display(static_cast<char>(str[0]));
    else if (type == "DLiteral")
        return ;
    else if (type == "FLiteral")
        return ;
    long double container;
    std::stringstream ss(str);
    ss >> container;
    if (ss.fail())
    {
        std::cerr << "Error in conversion to container" << std::endl;
        return ;
    }
    /*std::cout << "=======> container: " << container << std::endl;*/
    if (type == "int")
    {
        if (container > std::numeric_limits<int>::max() || container < std::numeric_limits<int>::min())
            std::cerr << "int overflow!!" << std::endl;
        else
            display(static_cast<int>(container));
    }
    else if (type == "float")
    {
        if (container > std::numeric_limits<float>::max() || container < -std::numeric_limits<float>::max())
            std::cerr << "float overflow!!" << std::endl;
        else
            display(static_cast<float>(container));
    }
    else if (type == "double")
    {
        if (container > std::numeric_limits<double>::max() || container < -std::numeric_limits<double>::max())
            std::cerr << "double overflow!!" << std::endl;
        else
            display(static_cast<double>(container));
    }
    /*std::cout << "good!!\n";*/
}

void ScalarConverter::convert(std::string str)
{
    std::cout << str << ": ";
    if (isChar(str))
    {
        typecast_str(str, "char");
        /*std::cout << "char\n";*/
    }
    else if (isInt(str))
    {
        typecast_str(str, "int");
        /*std::cout << "int\n";*/
    }
    else if (isDouble(str))
    {
        typecast_str(str, "double");
        /*std::cout << "double\n";*/
    }
    else if (isFloat(str))
    {
        typecast_str(str, "float");
        /*std::cout << "float\n";*/
    }
    else if (isDoubleLiteral(str))
    {
        typecast_str(str, "DLiteral");
        /*std::cout << "double\n";*/
    }
    else if (isFloatLiteral(str))
    {
        typecast_str(str, "FLiteral");
        /*std::cout << "float\n";*/
    }
    else
        std::cout << "invalid\n";
    std::cout << "=====================\n";
}
