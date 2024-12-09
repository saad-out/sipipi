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
}

void typecast_str(std::string &str, std::string type)
{
    if (type == "char")
        return display(static_cast<char>(str[0]));
    long double container;
    std::stringstream ss(str);
    ss >> container;
    if (ss.fail())
    {
        std::cerr << "Error in conversion to container" << std::endl;
        return ;
    }
    std::cout << "=======> container: " << container << std::endl;
    if (type == "int")
    {
        if (container > std::numeric_limits<int>::max() || container < std::numeric_limits<int>::min())
            std::cerr << "int overflow!!" << std::endl;
        return ;
    }
    if (type == "float")
    {
        if (container > std::numeric_limits<float>::max() || container < std::numeric_limits<float>::min())
            std::cerr << "float overflow!!" << std::endl;
        return ;
    }
    if (type == "double")
    {
        if (container > std::numeric_limits<double>::max() || container < std::numeric_limits<double>::min())
            std::cerr << "double overflow!!" << std::endl;
        return ;
    }
    std::cout << "good!!\n";
}

void ScalarConverter::convert(std::string str)
{
    std::cout << str << ": ";
    if (isChar(str))
    {
        typecast_str(str, "char");
        std::cout << "char\n";
    }
    else if (isInt(str))
    {
        typecast_str(str, "int");
        std::cout << "int\n";
    }
    else if (isDouble(str) || isDoubleLiteral(str))
    {
        typecast_str(str, "double");
        std::cout << "double\n";
    }
    else if (isFloat(str) || isFloatLiteral(str))
    {
        typecast_str(str, "float");
        std::cout << "float\n";
    }
    else
        std::cout << "invalid\n";
}
