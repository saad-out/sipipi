#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Unknown", 100, 100, 30) {
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap Name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap& other)
{
    std::cout << "FragTrap Copy assignement constructor called" << std::endl;
    ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "High fives!!" << std::endl;
}
