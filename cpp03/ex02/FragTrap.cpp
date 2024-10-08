#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Unknown") {
    std::cout << "FragTrap Default constructor called" << std::endl;
    hit = 100;
    energy = 100;
    damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap Name constructor called" << std::endl;
    hit = 100;
    energy = 100;
    damage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    FragTrap::operator=(other);
}

FragTrap& FragTrap::operator = (const FragTrap& other)
{
    std::cout << "FragTrap Copy assignement constructor called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "High fives from " << name << " !!" << std::endl;
}
