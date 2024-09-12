#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    ClapTrap obj1("p1"), obj2("p2");

    obj1.attack("p2");
    obj2.takeDamage(1337);
    obj2.attack("p1");
    obj2.takeDamage(100);
    obj2.attack("p1");
    obj2.beRepaired(1);
    for (int i = 0; i < 12; i++)
        obj2.attack("p1");
}
