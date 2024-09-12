#include <iostream>
#include "ScavTrap.hpp"

int main()
{
    ScavTrap a, b("JHON"), c(a), k("simo");
    k = b;


    std::cout << std::endl;
    std::cout << "a: ";
    a.info();
    std::cout << "b: ";
    b.info();
    std::cout << "c: ";
    c.info();
    std::cout << "k: ";
    k.info();
    std::cout << std::endl;

    a.attack("JHON");
    b.takeDamage(20);
    a.attack("JHON");
    b.takeDamage(200);
    b.takeDamage(200);
    std::cout << std::endl;

    a.guardGate();
    b.guardGate();
    std::cout << std::endl;

    return (0);
}
