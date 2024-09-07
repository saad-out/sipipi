#include <iostream>
#include "Zombie.hpp"

int main(int ac, char **av)
{
    std::string name;

    if (ac > 1)
        name = av[1];
    else
        name = "Jhon";
    Zombie *zombies = zombieHorde(5, name);
    for (int i = 0; i < 3; i++)
        zombies[i].announce();

    delete[] zombies;
}
