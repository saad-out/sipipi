#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
}

void HumanB::attack(void) const
{
    std::cout << name
              << " attacks with their "
              << ((weapon != NULL) ? weapon->getType() : "chi l3iba")
              << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
