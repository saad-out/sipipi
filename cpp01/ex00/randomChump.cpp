#include "Zombie.hpp"
#include <iostream>

void randomChump(std::string name)
{
    Zombie zombie = Zombie(name);
    zombie.announce();
}
