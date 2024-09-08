#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}

void HumanB::attack(void) const
{
    std::cout << name
              << " attacks with their "
              << (*weapon).getType()
              << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
