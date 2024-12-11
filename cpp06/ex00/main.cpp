#include "ScalarConverter.hpp"
#include <limits>

int main(int ac, char **av)
{
    if (ac < 2)
        return (1);
    ScalarConverter obj;

    for (int i = 1; i < ac; i++)
        obj.convert(av[i]);
    return (0);
}
