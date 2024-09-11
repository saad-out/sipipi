#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "Debugging message\n";
}

void Harl::info(void)
{
    std::cout << "Info message\n";
}

void Harl::warning(void)
{
    std::cout << "Warning message\n";
}

void Harl::error(void)
{
    std::cout << "Error message\n";
}

Level str_value(std::string& str)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    Level values[] = {Level::DEBUG, Level::INFO, Level::WARNING, Level::ERROR};
    for (int i = 0; i < 4; i++)
    {
        if (str == levels[i])
            return values[i];
    }
    return Level::UNKNOWN;
}

void Harl::complain(std::string level)
{
    void (Harl:: *ptr) (void);

    switch (str_value(level))
    {
        case Level::DEBUG:
            ptr = &Harl::debug;
            break;
        case Level::INFO:
            ptr = &Harl::info;
            break;
        case Level::WARNING:
            ptr = &Harl::warning;
            break;
        case Level::ERROR:
            ptr = &Harl::error;    
            break;
        default:
            ptr = nullptr;
            break;
    }
    if (ptr)
        (this->*ptr)();
}