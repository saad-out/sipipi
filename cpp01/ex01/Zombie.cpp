#include "Zombie.hpp"
#include <iostream>

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(void)
{
    this->name = "Unknown";
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << " destroyed." << std::endl;
}

Zombie& Zombie::operator=(const Zombie &other)
{
    std::cout << "copy constructor called" << std::endl;
    if (this != &other)
        name = other.name;
    return *this;
}
