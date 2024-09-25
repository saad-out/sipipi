#include <iostream>
#include <stdlib.h>
#include "Zombie.hpp"

int main(int ac, char **av)
{
    std::string name;
    int N = 5;

    if (ac > 1)
        name = av[1];
    else
        name = "Jhon";
    Zombie *zombies = zombieHorde(N, name);
    if (!zombies)
        return (EXIT_FAILURE);
    for (int i = 0; i < N; i++)
        zombies[i].announce();

    delete[] zombies;
}
