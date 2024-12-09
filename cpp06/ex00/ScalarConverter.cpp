#include "ScalarConverter.hpp"

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
    return (i == str.length());
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

void ScalarConverter::convert(std::string str) const
{
    std::cout << str << ": ";
    if (isChar(str))
        std::cout << "char\n";
    else if (isInt(str))
        std::cout << "int\n";
    else if (isDouble(str) || isDoubleLiteral(str))
        std::cout << "double\n";
    else if (isFloat(str) || isFloatLiteral(str))
        std::cout << "float\n";
    else
        std::cout << "invalid\n";
}
