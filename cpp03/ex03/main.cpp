#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap a("JHON");
    std::cout << std::endl;
    a.whoAmI();
    a.attack("target");
    /*a.info5();*/
    std::cout << std::endl;
    DiamondTrap b;
    std::cout << std::endl;
    b.whoAmI();
    b.attack("target");
    /*b.info5();*/
    std::cout << std::endl;
    DiamondTrap c(a);
    std::cout << std::endl;
    c.whoAmI();
    c.attack("target");
    /*c.info5();*/
    std::cout << std::endl;
    c = b;
    std::cout << std::endl;
    c.whoAmI();
    c.attack("target");
    /*c.info5();*/
    std::cout << std::endl;

    return (0);
}
