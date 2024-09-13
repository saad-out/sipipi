#include <iostream>
#include "FragTrap.hpp"

int main()
{
    FragTrap a, b("JHON"), c(a), k("simo");
    k = b;
    std::cout << std::endl;

    a.attack("JHON");
    b.takeDamage(20);
    a.attack("JHON");
    b.takeDamage(200);
    b.takeDamage(200);
    std::cout << std::endl;

    a.highFivesGuys();
    b.highFivesGuys();
    std::cout << std::endl;

    return (0);
}
