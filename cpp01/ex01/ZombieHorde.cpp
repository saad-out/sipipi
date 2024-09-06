#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    Zombie *zombies = new Zombie[5];
    for (int i = 0; i < 5; i++)
    {
        zombies[i] = Zombie("simo");
        zombies[i].announce();
    }
    delete[] zombies;
    return 1;
}
