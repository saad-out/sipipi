#include "Zombie.hpp"
#include <iostream>

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *zombies;

    if (N <= 0)
        return (NULL);
    try {
        zombies = new Zombie[N];
    } catch (std::bad_alloc&) {
        std::cerr << "Memory allocation overflow" << std::endl;
        return (NULL);
    };
    Zombie copy = Zombie(name);
    for (int i = 0; i < N; i++)
        zombies[i] = copy;
    return zombies;
}
