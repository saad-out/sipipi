#include "Zombie.hpp"
#include <iostream>

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *zombies = new Zombie[N];
    Zombie copy = Zombie(name);
    for (int i = 0; i < N; i++)
        zombies[i] = copy;
    return zombies;
}
