#include "Harl.hpp"

# define GREEN "\e[1;32m"
# define RESET "\e[0m"
# define RED "\e[1;91m"
# define CYAN "\e[1;36m"
# define YELLOW "\e[1;33m"
# define PURPLE "\e[1;35m"
# define BLUE "\e[1;34m"

void Harl::debug(void)
{
    std::cout << CYAN << "[ DEBUG ]\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
    std::cout << RESET;
}

void Harl::info(void)
{
    std::cout << PURPLE << "[ INFO ]\n";
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
    std::cout << RESET;
}

void Harl::warning(void)
{
    std::cout << YELLOW << "[ WARNING ]\n";
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
    std::cout << RESET;
}

void Harl::error(void)
{
    std::cout << RED << "[ ERROR ]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
    std::cout << RESET;
}

void Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl:: *array[]) (void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*array[i])();
            break;
        }
    }
}

void Harl::filter(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int i = 0;
    while (i < 4 && level != levels[i])
        i++;
    switch (i)
    {
        case DEBUG:
            debug();
            std::cout << "\n";
            /* fall through */
        case INFO:
            info();
            std::cout << "\n";
            /* fall through */
        case WARNING:
            warning();
            std::cout << "\n";
            /* fall through */
        case ERROR:
            error();
            std::cout << "\n";
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
}
