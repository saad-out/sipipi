#include <iostream>
#include "Zombie.hpp"

int main(void)
{
    // stack Zombie
    randomChump("stackZombie");

    // heap Zombie
    Zombie *heapZombie = newZombie("heapZombie");
    heapZombie->announce();

    // delete heap Zombie
    delete heapZombie;
    return 0;
}
