#include <iostream>
#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl obj;

    if (ac == 2)
        obj.filter(av[1]);
    else
        obj.filter("UNKNOWN");
    return (0);
}
